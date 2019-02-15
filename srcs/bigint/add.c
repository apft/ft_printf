/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:03:40 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 11:31:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	bigint_add(t_bigint *result, t_bigint *a, t_bigint *b)
{
	int				length;
	int				block;
	unsigned long	carry;
	unsigned long	sum;

	length = a->length < b ->length ? b->length : a->length;
	result->length = length;
	block = 0;
	carry = 0L;
	while (block < length)
	{
		sum = carry + (unsigned long)(a->blocks[block]) + (unsigned long)(b->blocks[block]);
		carry = sum >> BIGINT_SIZE_BLOCK;
		result->blocks[block] = sum & 0xffffffff;
		++block;
	}
	if (carry)
	{
		if (result->length < BIGINT_N_BLOCKS)
		{
			result->blocks[block] = 1;
			result->length += 1;
		}
		else
			result->blocks[block] = BIGINT_OVERFLOW;
	}
}
