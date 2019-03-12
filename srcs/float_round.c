/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:24:38 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 16:57:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils_float.h"

void		float_round(unsigned long n, char *base, char *str, t_specs *specs)
{
	int		b;
	int		id;
	int		next;
	int		next_next;
	int		j;
	int		propagate;

//	printf("dbg: %s\t%c%c\t%d\n", base, *(str-2), *(str-1), specs->precision);
	b = 0;
	while (*(base + b))
		++b;
	j = specs->precision;
	propagate = 1;
	if (propagate && !j && (((int)(n >> 60) > b / 2) || ((int)(n >> 60) == b / 2 && (*str - '0') % 2)))
	{
		(*(str - 1))++;
		return ;
	}
	while (propagate && j--)
	{
		propagate = 0;
		id = ((n << (4 * j)) & FLOAT_MASK_LEFT) >> 60;
		next = ((n << (4 * (j + 1))) & FLOAT_MASK_LEFT) >> 60;
		next_next = ((n << (4 * (j + 2))) & FLOAT_MASK_LEFT) >> 60;
//		printf("id= %d\tnext= %d\n", id, next);
		if (next > (b / 2))
			id += 1;
		if (next == (b / 2) && next_next)
			id += 1;
		if (id == b)
			propagate = 1;
//		printf("digit= %c\n", *(base + (id == b ? 0 : id)));
		*(str--) = *(base + (id == b ? 0 : id));
		if (propagate && *str == '.')
			(*(str - 1))++;
	//printf("last digit is: %c %d\n", *(base + id), id);
	}
}

