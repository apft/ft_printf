/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_bigint_is_underflow.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:07:04 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 12:13:42 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_is_underflow(void)
{
	t_bigint	a;
	int			err;

	bigint_init_null(&a);
	a.blocks[BIGINT_N_BLOCKS] = BIGINT_UNDERFLOW;
	a.blocks[0] = 7956;
	err = !bigint_is_underflow(&a);
	if (err)
		print_bigint(&a);
	return (err);
}
