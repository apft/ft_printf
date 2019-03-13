/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/03/13 16:41:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"
#include "bigint.h"
#include "filler.h"
#include "filter.h"

#include <stdio.h>
void	extract_mantissa(t_bigint *numerator, unsigned long frac,
							unsigned long exp)
{
	t_bigint	implicit_bit;

	bigint_init_null(numerator);
	numerator->blocks[0] = (unsigned int)(frac & BIGINT_MASK_BLOCK);
	numerator->blocks[1] = (unsigned int)(frac >> BIGINT_SIZE_BLOCK);
	if (exp)
	{
		bigint_init_int(&implicit_bit, 1);
		bigint_shift_left_self(&implicit_bit, FLOAT_SIZE_FRAC);
		bigint_add(numerator, numerator, &implicit_bit);
	}
}

int		get_quotient_and_substract(t_bigint *numerator, t_bigint *denominator)
{
	int			quotient;
	t_bigint	result_tmp;

	if (bigint_cmp(numerator, denominator) < 0)
		return (0);
	quotient = 5;
	bigint_init_null(&result_tmp);
	bigint_mult_int(&result_tmp, denominator, quotient);
	while (bigint_cmp(&result_tmp, numerator) < 0 && quotient++)
		bigint_add(&result_tmp, &result_tmp, denominator);
	while (bigint_cmp(&result_tmp, numerator) > 0 && quotient--)
		bigint_sub(&result_tmp, &result_tmp, denominator);
	bigint_sub(numerator, numerator, &result_tmp);
	return (quotient);
}

static void	generate_bigint_pow_ten(t_bigint *bigint_pow_ten, int pow_ten)
{
	while (pow_ten--)
		bigint_mult_int(bigint_pow_ten, bigint_pow_ten, 10);
}

static void	generate_bigints_num_den(t_bigint *numerator, t_bigint *denominator,
							union u_double *value, int pow_ten)
{
	int			exp;
	t_bigint	bigint_pow_ten;

	extract_mantissa(numerator, value->field.frac, value->field.exp);
	bigint_init_int(denominator, 1);
	exp = value->field.exp ? value->field.exp : 1;
	exp -= (FLOAT_EXP_BIAS_DBL + FLOAT_SIZE_FRAC);
	if (exp >= 0)
		bigint_shift_left_self(numerator, exp);
	else
		bigint_shift_left_self(denominator, -exp);
	bigint_init_int(&bigint_pow_ten, 1);
	if (pow_ten > 0)
	{
		generate_bigint_pow_ten(&bigint_pow_ten, pow_ten);
		bigint_mult(denominator, denominator, &bigint_pow_ten);
	}
	else if (pow_ten < 0)
	{
		generate_bigint_pow_ten(&bigint_pow_ten, -pow_ten);
		bigint_mult(numerator, numerator, &bigint_pow_ten);
	}
}

static int	fill_float_floor_part(char *str, int pow_ten, t_bigint *numerator,
									t_bigint *denominator)
{
	int		i;
	int			digit;

	i = 0;
	if (pow_ten < 0)
	{
		*(str + i++) = '0';
		return (i);
	}
	while (i <= pow_ten)
	{
		digit = get_quotient_and_substract(numerator, denominator);
		*(str + i++) = '0' + (char)digit;
		bigint_mult_int(numerator, numerator, 10);
	}
	return (i);
}

static int	fill_float_decimal_part(char *str, int pow_ten, int precision,
									t_bigint *numerator, t_bigint *denominator)
{
	int		i;
	int			digit;

	i = 0;
	if (pow_ten < 0)
		while (i < precision && ++pow_ten)
			*(str + i++) = '0';
	while (i < precision && !bigint_is_null(numerator))
	{
		digit = get_quotient_and_substract(numerator, denominator);
		*(str + i++) = '0' + (char)digit;
		bigint_mult_int(numerator, numerator, 10);
	}
	return (i);
}

static int	propagate_rounding(char *str, int limit)
{
	int		propagate;
	int		i;

	propagate = 1;
	i = 0;
	while (i < limit && propagate)
	{
		if (*(str - i) == '9')
			*(str - i) = '0';
		else
		{
			*(str - i) += 1;
			propagate = 0;
		}
		++i;
	}
	return (propagate);
}

static void	apply_rounding(int pow_ten, int precision, char *str)
{
	int		propagate;

	propagate = 1;
	if (precision)
		propagate = propagate_rounding(str, precision);
	if (propagate)
	{
		if (*str == '.')
			propagate_rounding(str - 1, pow_ten);
		else
			propagate_rounding(str, pow_ten);
	}

}

static void	apply_rounding_if_needed(char *str, int pow_ten, int precision,
									t_bigint *numerator, t_bigint *denominator)
{
	int		digit_after;

	if (bigint_is_null(numerator))
		return ;
	digit_after = get_quotient_and_substract(numerator, denominator);
	if (digit_after > 5)
		apply_rounding(pow_ten, precision, str);
	else if (digit_after == 5)
	{
		bigint_mult_int(numerator, numerator, 10);
		digit_after = get_quotient_and_substract(numerator, denominator);
		while (digit_after == 0 && !bigint_is_null(numerator))
		{
			bigint_mult_int(numerator, numerator, 10);
			digit_after = get_quotient_and_substract(numerator, denominator);
		}
		if (digit_after)
			apply_rounding(pow_ten, precision, str);
		else
		{
			if (pf_isdigit(*str) && (*str % 2) == 1)
				apply_rounding(pow_ten, precision, str);
			else if (*str == '.' && (*(str - 1) % 2) == 1)
				apply_rounding(pow_ten, precision, str - 1);
		}
	}
}

static void	fill_str(union u_double *value, char *str, t_specs *specs)
{
	t_bigint	numerator;
	t_bigint	denominator;
	int			pow_ten;
	int			i;
	int			decimal_length;

	pow_ten = pf_compute_float_pow_ten(value->type_dbl);
	generate_bigints_num_den(&numerator, &denominator, value, pow_ten);
	i = filler(str, specs, FILL_START);
	i += fill_float_floor_part(str + i, pow_ten, &numerator, &denominator);
	if (specs->precision || (specs->flags & FLOAT_FORCE_POINT))
		*(str + i++) = '.';
	decimal_length = i;
	i += fill_float_decimal_part(str + i, pow_ten, specs->precision,
								&numerator, &denominator);
	if (!bigint_is_null(&numerator)
			&& !(pow_ten < 0 && (specs->precision + 1 + pow_ten) < 0))
		apply_rounding_if_needed(str + i - 1, pow_ten, specs->precision,
								&numerator, &denominator);
	while (i - decimal_length < specs->precision)
		*(str + i++) = '0';
	while (i < specs->width)
		*(str + i++) = ' ';
}

static int	compute_width_arg_float(union u_double *value, t_specs *specs)
{
	int		width_arg;
	int		pow_ten;

	width_arg = 1;
	pow_ten = pf_compute_float_pow_ten(value->type_dbl);
	if (pow_ten > 0)
		width_arg += pow_ten;
	if ((specs->flags & PRECISION) &&
			(specs->precision || (specs->flags & FLOAT_FORCE_POINT)))
		width_arg += 1;
	width_arg += specs->precision;
	return (width_arg);
}

int			handle_float_conv(union u_double *value, t_specs *specs, char *str)
{
	specs->is_neg = value->field.sign;
	if (!(specs->flags & PRECISION))
	{
		specs->flags |= PRECISION;
		specs->precision = FLOAT_DEFAULT_PRECISION;
	}
	if (specs->flags & PREFIX)
	{
		specs->flags ^= PREFIX;
		specs->flags |= FLOAT_FORCE_POINT;
	}
	specs->width_prefix = specs->is_neg;
	if (!specs->is_neg)
		specs->width_prefix += !!(specs->flags & (PLUS | SPACE));
	specs->width_arg = compute_width_arg_float(value, specs);
	filter_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}
