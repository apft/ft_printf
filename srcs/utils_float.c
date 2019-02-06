/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 12:25:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils_float.h"

#include <stdio.h>
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
	print_bits(value->l, 8 * sizeof(value->l));
	printf("\n\e[4m%-6s\t%-17s\t%-65s\e[0m\n", "sign", "exp", "significand");
	print_bits(value->field.sign, FLOAT_SIZE_SIGN);
	print_bits(value->field.exp, FLOAT_SIZE_EXP);
	print_bits(value->field.frac, FLOAT_SIZE_FRAC);
	printf("\n");
}
