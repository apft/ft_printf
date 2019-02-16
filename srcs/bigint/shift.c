/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:58:42 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:34:56 by apion            ###   ########.fr       */
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
	unsigned int	i;
	unsigned int	carry;

	offset = shift / BIGINT_SIZE_BLOCK;
	mod = shift % BIGINT_SIZE_BLOCK;
	i = input->length;
	if ((!mod && i + offset > BIGINT_N_BLOCKS)
				|| (mod && i + offset >= BIGINT_N_BLOCKS))
		result->blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	else
	{
		result->length = i + offset;
		while (i--)
		{
			carry = 0;
			if (mod)
				carry = input->blocks[i] >> (BIGINT_SIZE_BLOCK - mod);
			result->blocks[i + offset + 1] += carry;
			result->blocks[i + offset] = input->blocks[i] << mod;
			if ((i + 1) == input->length && carry)
				result->length += 1;
		}
		if (!mod && offset)
			while (offset--)
				result->blocks[offset] = 0;
	}
}
