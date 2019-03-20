/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 12:54:04 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_pf.h"
#include "utils.h"
#include <stdio.h>
static int	float_compute_pow_ten_long_dbl(long double n)
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

static int	float_compute_pow_ten_dbl(double n)
{
	return (float_compute_pow_ten_long_dbl((long double)n));
}

int			float_compute_pow_ten(union u_double *value, int flag)
{
	if (flag & MOD_LD)
		return (float_compute_pow_ten_long_dbl(value->type_long_dbl));
	return (float_compute_pow_ten_dbl(value->type_dbl));
}

void		print_bits(long n, unsigned int size)
{
	unsigned int		i;

	printf("%ld: ", n);
	i = size;
	while (i--)
		printf("%d", (int)((n >> i) & 1));
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
void		dbg_print_ld(union u_double *value)
{
	printf("\e[4mvalue\e[0m\n");
//	print_bits(value->type_ll, 8 * sizeof(value->type_ll));
	printf("\n\e[4m%-6s\t%-17s\t%-65s\e[0m\n", "sign", "exp", "significand");
	print_bits(value->field_ld.sign, FLOAT_LD_SIZE_SIGN);
	print_bits(value->field_ld.exp, FLOAT_LD_SIZE_EXP);
	print_bits(value->field_ld.int_part, FLOAT_LD_INTEGER_PART);
	print_bits(value->field_ld.frac, FLOAT_LD_SIZE_FRAC);
	printf("\n");
}
