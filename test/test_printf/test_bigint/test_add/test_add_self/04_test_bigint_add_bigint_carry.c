/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_add_bigint_carry.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:40:58 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:19:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_self_bigint_carry(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {257, BIGINT_BLOCK_MAX_VALUE, 0, 0, 0}};
	b = (t_bigint){3, {42, 789, 468, 0, 0}};
	expected = (t_bigint){3, {257 + 42,
		(BIGINT_BLOCK_MAX_VALUE + 789) - BIGINT_BLOCK_MAX_VALUE - 1,
		468 + 1,
		0,
		0}};

	bigint_add(&a, &a, &b);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(0, &b, &a, &expected, diff);	
	return (diff);
}
