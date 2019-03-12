/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_init_int_max.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:49:39 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 16:40:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"
#include <stdio.h>

int		test_bigint_init_int_max(void)
{
	t_bigint		a;
	unsigned int	n;
	int				err;
	int				i;

	n = 0xffffffff;
	bigint_init_int(&a, n);
	err = 0;
	i = 1;
	while (!err && i < BIGINT_N_BLOCKS)
		err += a.blocks[i++];
	err += !(a.blocks[0]  == n) || !(a.length == 1);
	if (err)
	{
		printf("a should be %#x = %u\n", n, n);
		printf("length = %d\n", a.length);
		print_bigint(&a);
	}
	return (err);
}
