/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/03/14 09:24:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "bigint.h"
#include "filler.h"
#include "filter.h"

#include <stdio.h>

static int float_will_round_to_ten(union u_double *value, int pow_ten, int precision)
{
	t_bigint	numerator;
	t_bigint	denominator;
	int			i;
	int			digit;
	int			digit_after;

	generate_bigints_num_den(&numerator, &denominator, value, pow_ten);
	digit = get_quotient_and_substract(&numerator, &denominator);
	if (pow_ten < 0)
		pow_ten *= -1;
	if (digit != 9)
		return (0);
	bigint_mult_int(&numerator, &numerator, 10);
	digit_after = get_quotient_and_substract(&numerator, &denominator);
	i = 0;
	while (digit_after == 9 && i < (pow_ten + precision) && !bigint_is_null(&numerator))
	{
		bigint_mult_int(&numerator, &numerator, 10);
		digit_after = get_quotient_and_substract(&numerator, &denominator);
		++i;
	}
	if (digit_after >= 5 && i == (pow_ten + precision))
		return (1);
	if (digit_after > 5 && bigint_is_null(&numerator))
		return (1);
	return (0);
}

static int	fill_float_floor_part(char *str, int pow_ten, int is_round_ten, t_bigint *numerator,
									t_bigint *denominator)
{
	int		i;
	int		digit;

	i = 0;
	if (pow_ten < 0 && !is_round_ten)
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
	if ((specs->flags & FLOAT_ROUND_TEN) && pow_ten >= -1)
		*(str + i++) = '1';
	i += fill_float_floor_part(str + i, pow_ten, specs->flags & FLOAT_ROUND_TEN, &numerator, &denominator);
	if (specs->precision || (specs->flags & FLOAT_FORCE_POINT))
		*(str + i++) = '.';
	decimal_length = i;
	i += fill_float_decimal_part(str + i, pow_ten, specs->precision,
								&numerator, &denominator);
	if (!bigint_is_null(&numerator)
			&& !(pow_ten < 0 && (specs->precision + 1 + pow_ten) < 0))
		float_apply_rounding_if_needed(str + i - 1, pow_ten, specs->precision,
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
	if (pow_ten >= -1 && float_will_round_to_ten(value, pow_ten, specs->precision))
	{
		specs->flags |= FLOAT_ROUND_TEN;
		width_arg += (pow_ten >= 0) ? 1 : 0;
	}
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
