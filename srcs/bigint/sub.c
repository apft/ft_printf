/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:19:35 by apion             #+#    #+#             */
/*   Updated: 2019/03/11 15:39:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static void	sub_and_shrink_length(t_bigint *result, t_bigint *a, t_bigint *b)
{
	unsigned int	i;
	int				n_null_block;
	unsigned int	alpha;
	unsigned int	beta;
	unsigned int	carry;

	n_null_block = 0;
	carry = 0;
	i = 0;
	while (i < result->length)
	{
		alpha = a->blocks[i];
		beta = b->blocks[i];
		a->blocks[i] += carry;
		if (alpha >= beta)
			result->blocks[i] = alpha - beta;
		else
		{
			a->blocks[i + 1] -= 1;
			result->blocks[i] = (unsigned int)((1UL << 32) + alpha - beta);
			carry = 1;
		}
		n_null_block = (result->blocks[i] == 0 && i) ? n_null_block + 1 : 0;
		++i;
	}
	result->length -= n_null_block;
}

void		bigint_sub_int(t_bigint *result, t_bigint *a, unsigned int n)
{
	t_bigint	b;

	bigint_init_int(&b, n);
	bigint_sub(result, a, &b);
}

void		bigint_sub(t_bigint *result, t_bigint *a, t_bigint *b)
{
	if (bigint_is_underflow(a) || bigint_is_underflow(b)
			|| bigint_cmp(a, b) < 0)
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_UNDERFLOW;
	else
	{
		result->length = a->length;
		sub_and_shrink_length(result, a, b);
	}
}
