/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_add_bigint_carry.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:40:58 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 17:22:08 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_bigint_carry(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {257, 0xffffffff, 0, 0, 0}};
	b = (t_bigint){3, {42, 789, 468, 0, 0}};
	result = (t_bigint){0};
	expected = (t_bigint){3, {299, 0xffffffff, 1257, 0, 0}};

	bigint_add(&result, &a, &b);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &b, &result, &expected, diff);	
	return (diff);
}
