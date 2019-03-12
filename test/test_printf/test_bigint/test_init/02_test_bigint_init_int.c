/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_init_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:42:26 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 16:39:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"
#include <stdio.h>

int		test_bigint_init_int(void)
{
	t_bigint		a;
	unsigned int	n;
	int				err;
	int				i;

	n = 42;
	bigint_init_int(&a, n);
	err = 0;
	i = 1;
	while (!err && i < BIGINT_N_BLOCKS)
		err += a.blocks[i++];
	err += !(a.blocks[0] == n) || !(a.length == 1);
	if (err)
	{
		printf("a should be %#x = %u\n", n, n);
		printf("length = %d\n", a.length);
		print_bigint(&a);
	}
	return (err);
}
