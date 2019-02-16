/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:03:40 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 13:09:25 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	bigint_add(t_bigint *result, t_bigint *a, t_bigint *b)
{
	int				i;
	unsigned long	carry;
	unsigned long	sum;

	result->length = (a->length < b->length) ? b->length : a->length;
	i = 0;
	carry = 0UL;
	while (i < result->length)
	{
		sum = carry;
		sum += (unsigned long)(a->blocks[i]) + (unsigned long)(b->blocks[i]);
		carry = sum >> BIGINT_SIZE_BLOCK;
		result->blocks[i] = sum & BIGINT_MASK_BLOCK;
		++i;
	}
	if (carry)
	{
		if (result->length < BIGINT_N_BLOCKS)
		{
			result->blocks[i] = carry;
			result->length += 1;
		}
		else
			result->blocks[i] = BIGINT_OVERFLOW;
	}
}

void	bigint_add_int(t_bigint *result, t_bigint *a, unsigned int n)
{
	t_bigint	b;

	bigint_init_int(&b, n);
	bigint_add(result, a, &b);
}
