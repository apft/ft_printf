/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:09:23 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 11:31:01 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

#include <stdio.h>
static void	print_borders()
{
	int		width_block;
	int		i;

	width_block = BIGINT_SIZE_BLOCK;
	i = (width_block + 1) * (BIGINT_N_BLOCKS + 1) + 1;
	while (--i)
		printf("%c", i % (width_block + 1) == 0 ? '+' : '-');
	printf("+\n");
}

static void	print_blocks_number(unsigned int n)
{
	int		i;
	char	highlight;

	i = BIGINT_N_BLOCKS + 1;
	printf("|");
	while (i--)
	{
		highlight = i == (n - 1) ? '*' : ' ';
		printf("%13s%c %2d %c%13s|", "", highlight, i, highlight, "");
	}
	printf("\n");
}

void	print_bits(unsigned int n)
{
	int		i;

	i = BIGINT_SIZE_BLOCK;
	while (i--)
		printf("%d", (n >> i) & 1);
	printf("|");
}

static void	print_blocks(unsigned int *blocks)
{
	int		i;

	i = BIGINT_N_BLOCKS + 1;
	printf("|");
	while (i--)
		print_bits(blocks[i]);
	printf("\n");
}

void	print_big_int(t_bigint *bigint)
{
	print_borders();
	print_blocks(bigint->blocks);
	print_borders();
	print_blocks_number(bigint->length);
}
