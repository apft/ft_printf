/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:58:42 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 11:32:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	bigint_shift_left_self(t_bigint *result, unsigned int shift)
{
	bigint_shift_left(result, result, shift);
}

void	bigint_shift_left(t_bigint *result, t_bigint *input, unsigned int shift)
{
	unsigned int	offset;
	unsigned int	mod;
	unsigned int	block;
	unsigned int	tmp;

	offset = shift / BIGINT_SIZE_BLOCK;
	mod = shift % BIGINT_SIZE_BLOCK;
	block = input->length;
	if ((!mod && block + offset > BIGINT_N_BLOCKS)
				|| (mod && block + offset >= BIGINT_N_BLOCKS))
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
	{
		result->length = block + offset;
		while (block--)
		{
			tmp = 0;
			if (mod)
				tmp = input->blocks[block] >> (BIGINT_SIZE_BLOCK - mod);
			result->blocks[block + offset + 1] += tmp;
			result->blocks[block + offset] = input->blocks[block] << mod;
			if (tmp)
				result->length += 1;
		}
		if (!mod && offset)
			while (offset--)
				result->blocks[offset] = 0;
	}
}
