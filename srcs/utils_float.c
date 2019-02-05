/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/02/05 20:36:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils_float.h"

#include <stdio.h>
void		pf_round(unsigned long n, char *base, char *str, t_specs *specs)
{
	int		b;
	int		id;
	int		next;
	int		j;
	int		propagate;

//	printf("dbg: %s\t%c%c\t%d\n", base, *(str-2), *(str-1), specs->precision);
	b = 0;
	while (*(base + b))
		++b;
	j = specs->precision;
	propagate = 1;
	if (propagate && !j && (((n >> 60) > b / 2) || ((n >> 60) == b / 2 && (*str - '0') % 2)))
	{
		(*(str - 1))++;
		return ;
	}
	while (propagate && j--)
	{
		propagate = 0;
		id = ((n << (4 * j)) & FLOAT_MASK_LEFT) >> 60;
		next = ((n << (4 * (j + 1))) & FLOAT_MASK_LEFT) >> 60;
//		printf("id= %d\tnext= %d\n", id, next);
		if (next > (b / 2))
			id += 1;
		if (next == (b / 2) && id % 2)
			id += 1;
		if (id == b)
			propagate = 1;
//		printf("digit= %c\n", *(base + (id == b ? 0 : id)));
		*(str--) = *(base + (id == b ? 0 : id));
		if (propagate && *str == '.')
			(*(str - 1))++;
		--j;
	//printf("last digit is: %c %d\n", *(base + id), id);
	}
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
	print_bits(value->l, 8 * sizeof(value->l));
	printf("\n\e[4m%-6s\t%-17s\t%-65s\e[0m\n", "sign", "exp", "significand");
	print_bits(value->field.sign, FLOAT_SIZE_SIGN);
	print_bits(value->field.exp, FLOAT_SIZE_EXP);
	print_bits(value->field.frac, FLOAT_SIZE_FRAC);
	printf("\n");
}
