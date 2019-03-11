/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/03/11 18:42:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"
#include "bigint.h"
#include "filler.h"

#include <stdio.h>
int		compute_pow_ten(double n)
{
	int		pow_ten;

	pow_ten = 0;
	if (n > 10.0)
	{
		while (n > 10.0)
		{
			n /= 10;
			++pow_ten;
		}
	}
	else if (n < 1.0)
	{
		while (n < 1.0)
		{
			n *= 10;
			--pow_ten;
		}
	}
	return (pow_ten);
}

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

void	generate_bigints(union u_double *value)
{
	int		exp;
	int		pow_ten;
	t_bigint	numerator;
	t_bigint	denominator;
	t_bigint	bigint_pow_ten;
	int			i;
	int			digit;

	extract_mantissa(&numerator, value->field.frac, value->field.exp);
	bigint_init_int(&denominator, 1);
	exp = value->field.exp - 1023 - FLOAT_SIZE_FRAC;
	pow_ten = compute_pow_ten(value->type_dbl);
	printf("exp: %d\npow_ten: %d\n", exp, pow_ten);
	if (exp >= 0)
		bigint_shift_left_self(&numerator, exp);
	else
		bigint_shift_left_self(&denominator, -exp);
	bigint_init_int(&bigint_pow_ten, 1);
	if (pow_ten > 0)
	{
		i = pow_ten;
		while (i--)
			bigint_mult_int(&bigint_pow_ten, &bigint_pow_ten, 10);
		bigint_mult(&denominator, &denominator, &bigint_pow_ten);
	}
	else if (pow_ten < 0)
	{
		i = -pow_ten;
		while (i--)
			bigint_mult_int(&bigint_pow_ten, &bigint_pow_ten, 10);
		bigint_mult(&numerator, &numerator, &bigint_pow_ten);
	}
	i = 0;
	if (bigint_is_overflow(&numerator))
		return ;
	while (!bigint_is_null(&numerator) && !bigint_is_underflow(&numerator))
	{
		digit = get_quotient_and_substract(&numerator, &denominator);
		printf("%d ", digit);
		bigint_mult_int(&numerator, &numerator, 10);
		++i;
	}
	printf("\ni: %d\n", i);
}

int			handle_float_conv(union u_double *value, t_specs *specs, char *str)
{
	(void)specs;
	if (str)
	{
		dbg_print(value);
		generate_bigints(value);
	}
	return (1);
}
