/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/03/14 09:29:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_pf.h"

#include "utils.h"
#include <stdio.h>
int		float_will_round_to_ten(union u_double *value, int pow_ten, int precision)
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

int		float_compute_pow_ten(double n)
{
	int		pow_ten;

	pow_ten = 0;
	if (!n)
		return (pow_ten);
	if (n < 0)
		n *= -1;
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

void		print_bits(long n, unsigned int size)
{
	unsigned int		i;

	printf("%ld: ", n);
	i = size;
	while (i--)
		printf("%ld", (n >> i) & 1);
	printf("\t");
}
void		dbg_print(union u_double *value)
{
	printf("\e[4mvalue\e[0m\n");
	print_bits(value->type_long, 8 * sizeof(value->type_long));
	printf("\n\e[4m%-6s\t%-17s\t%-65s\e[0m\n", "sign", "exp", "significand");
	print_bits(value->field.sign, FLOAT_SIZE_SIGN);
	print_bits(value->field.exp, FLOAT_SIZE_EXP);
	print_bits(value->field.frac, FLOAT_SIZE_FRAC);
	printf("\n");
}
