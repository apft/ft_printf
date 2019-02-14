/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:09:23 by apion             #+#    #+#             */
/*   Updated: 2019/02/14 13:51:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

#include <stdio.h>
static void	print_borders()
{
	int		width_block;
	int		i;

	width_block = 8 * sizeof(int);
	i = (width_block + 1) * (BIG_INT_BLOCKS_SIZE + 1) + 1;
	while (--i)
		printf("%c", i % (width_block + 1) == 0 ? '+' : '-');
	printf("+\n");
}

static void	print_blocks_number(int n)
{
	int		width_block;
	int		i;
	char	highlight;

	width_block = 8 * sizeof(int);
	i = BIG_INT_BLOCKS_SIZE + 1;
	printf("|");
	while (i--)
	{
		highlight = i == (n - 1) ? '*' : ' ';
		printf("%13s%c %2d %c%13s|", "", highlight, i, highlight, "");
	}
	printf("\n");
}

static void	print_bits(int n)
{
	int		size;
	int		i;

	size = 8 * sizeof(n);
	i = size;
	while (i--)
		printf("%d", (n >> i) & 1);
	printf("|");
}

static void	print_blocks(int *blocks)
{
	int		i;

	i = BIG_INT_BLOCKS_SIZE + 1;
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
