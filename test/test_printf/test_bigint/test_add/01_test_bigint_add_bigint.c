/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_add_bigint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:11:12 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 12:51:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		test_bigint_add_bigint(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){1, {256, 0, 0, 0, 0}};
	b = (t_bigint){2, {42, 789, 0, 0, 0}};
	result = (t_bigint){0};
	expected = (t_bigint){2, {298, 789, 0, 0, 0}};
	
	bigint_add(&result, &a, &b);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &b, &result, &expected, diff);	
	return (diff);
}
