/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bigint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 08:54:19 by apion             #+#    #+#             */
/*   Updated: 2019/03/14 14:20:28 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_pf.h"
#include "bigint.h"

static void	extract_mantissa(t_bigint *numerator, unsigned long frac,
							unsigned long exp)
{
	t_bigint	implicit_bit;

	bigint_init_null(numerator);
	numerator->blocks[0] = (unsigned int)(frac & BIGINT_MASK_BLOCK);
	numerator->blocks[1] = (unsigned int)(frac >> BIGINT_SIZE_BLOCK);
	if (numerator->blocks[1])
		numerator->length += 1;
	if (exp)
	{
		bigint_init_int(&implicit_bit, 1);
		bigint_shift_left_self(&implicit_bit, FLOAT_SIZE_FRAC);
		bigint_add(numerator, numerator, &implicit_bit);
	}
}

static void	generate_bigint_pow_ten(t_bigint *bigint_pow_ten, int pow_ten)
{
	bigint_init_int(bigint_pow_ten, 1);
	if (pow_ten < 0)
		pow_ten *= -1;
	while (pow_ten--)
		bigint_mult_int(bigint_pow_ten, bigint_pow_ten, 10);
}

int			get_quotient_and_substract(t_bigint *numerator,
										t_bigint *denominator)
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

void		generate_bigints_num_den(union u_double *value, int pow_ten,
							t_bigint *numerator, t_bigint *denominator)
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
	generate_bigint_pow_ten(&bigint_pow_ten, pow_ten);
	if (pow_ten > 0)
		bigint_mult(denominator, denominator, &bigint_pow_ten);
	else if (pow_ten < 0)
		bigint_mult(numerator, numerator, &bigint_pow_ten);
}
