/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_bigint_add_int_carry.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:16:53 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:20:55 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_self_int_carry(void)
{
	t_bigint	a;
	int			n;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){1, {256, 0, 0, 0, 0}};
	n = 0xffffffff - 250;
	expected = (t_bigint){2, {
		(n + 256) - BIGINT_BLOCK_MAX_VALUE - 1,
		1,
		0,
		0,
		0}};

	bigint_add_int(&a, &a, n);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(0, 0, &a, &expected, diff);	
	return (diff);
}
