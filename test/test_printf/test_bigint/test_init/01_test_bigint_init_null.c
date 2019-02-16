/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_init_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:37:31 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 11:58:25 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_init_null(void)
{
	t_bigint	a;
	int			err;
	int			i;

	bigint_init_null(&a);
	err = 0;
	i = 0;
	while (!err && i < BIGINT_N_BLOCKS)
		err += a.blocks[i++];
	err += !(a.length == 1);
	if (err)
	{
		printf("a should be 0\n");
		printf("length = %d\n", a.length);
		print_bigint(&a);
	}
	return (err);
}
