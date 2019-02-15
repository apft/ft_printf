/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_add_bigint_overflow.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:43:31 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 16:48:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_bigint_overflow(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){1, {256, 0, 0, 0xffffffff, 0}};
	b = (t_bigint){2, {42, 789, 0, 2, 0}};
	result = (t_bigint){0};
	expected = (t_bigint){2, {298, 789, 0, 0, 0}};

	bigint_add(&result, &a, &b);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &b, &result, &expected, diff);	
	return (diff);
}
