/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:58:42 by apion             #+#    #+#             */
/*   Updated: 2019/02/14 17:55:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void	bigint_shift_left_self(t_bigint *result, unsigned int shift)
{
	bigint_shift_left(result, result, shift);
}

void	bigint_shift_left(t_bigint *result, t_bigint *input, unsigned int shift)
{
	unsigned int	offset;
	unsigned int	block;
	unsigned int	tmp;
	unsigned int	mod;

	offset = shift / BIGINT_SIZE_BLOCK;
	block = input->length;
	printf("shift= %d\toffset= %d\tblock= %d\n", shift, offset, block);
	if (block + offset > BIGINT_N_BLOCKS)
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
	{
		result->length = block + offset;
		if ((mod = shift % BIGINT_SIZE_BLOCK) == 0)
		{
			while (block--)
				result->blocks[block + offset] = input->blocks[block];
			while (offset--)
				result->blocks[offset] = 0;
		}
		else
		{
			while (block--)
			{
				tmp = input->blocks[block] >> (BIGINT_SIZE_BLOCK - mod);
				result->blocks[block + offset + 1] += tmp;
				result->blocks[block + offset] = input->blocks[block] << mod;
				if (tmp)
					result->length += 1;
			}
		}
	}
}
