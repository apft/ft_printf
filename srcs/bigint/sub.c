/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:19:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 13:48:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static void	sub_and_shrink_length(t_bigint *result, t_bigint *a, t_bigint *b)
{
	int				i;
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
		if (alpha >= beta)
			result->blocks[i] = alpha - beta - carry;
		else
		{
			result->blocks[i] = alpha + (~beta) - 1 - carry;
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
