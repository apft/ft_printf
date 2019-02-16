/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_bigint_sub_int_carry.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:16:53 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 18:26:41 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_int_carry(void)
{
	t_bigint	a;
	int			n;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){1, {256, 0, 0, 0, 0}};
	n = 0xffffffff - 250;
	bigint_init_null(&result);
	expected = (t_bigint){2, {
		(n + 256) - BIGINT_BLOCK_MAX_VALUE - 1,
		1,
		0,
		0,
		0}};

	bigint_sub_int(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
