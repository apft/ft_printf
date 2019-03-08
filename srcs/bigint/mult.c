/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:52:34 by apion             #+#    #+#             */
/*   Updated: 2019/03/06 19:32:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void		bigint_mult_int(t_bigint *result, t_bigint *a, unsigned int n)
{
	unsigned int	block;
	unsigned long	mult;
	unsigned long	carry;

	if (bigint_is_overflow(a))
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
	{
		carry = 0UL;
		block = 0;
		while (block < a->length)
		{
			mult = carry;
			mult += ((unsigned long)a->blocks[block]) * ((unsigned long)n);
			carry = mult >> BIGINT_SIZE_BLOCK;
			result->blocks[block++] = mult & BIGINT_MASK_BLOCK;
		}
		if (block == BIGINT_N_BLOCKS && carry)
			result->blocks[block] = BIGINT_OVERFLOW;
		else
		{
			result->blocks[block] = carry;
			result->length = a->length + (carry ? 1 : 0);
		}
	}
}

void		bigint_mult_by_basis(t_bigint *result, t_bigint *a, t_bigint *basis)
{
	unsigned int	basis_index;

	basis_index = basis->length - 1;
	if (a->length + basis_index > BIGINT_N_BLOCKS)
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
		bigint_shift_left(result, a, basis_index * BIGINT_SIZE_BLOCK);
}

static void	bigint_mult_by_smaller(t_bigint *result, t_bigint *a, t_bigint *b)
{
	unsigned int	block;
	t_bigint		tmp;
	t_bigint		basis;

	bigint_init_null(&basis);
	block = 0;
	while (block < b->length && !bigint_is_overflow(result))
	{
		bigint_init_null(&tmp);
		basis.blocks[block] = 1;
		bigint_mult_int(&tmp, a, b->blocks[block]);
		bigint_mult_by_basis(&tmp, &tmp, &basis);
		bigint_add(result, &tmp, result);
		basis.blocks[block] = 0;
		basis.length += 1;
		++block;
	}
}

void		bigint_mult(t_bigint *result, t_bigint *a, t_bigint *b)
{
	if (bigint_is_overflow(a) || bigint_is_overflow(b))
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
	{
		if (bigint_cmp(a, b) < 0)
			bigint_mult_by_smaller(result, b, a);
		else
			bigint_mult_by_smaller(result, a, b);
	}
}