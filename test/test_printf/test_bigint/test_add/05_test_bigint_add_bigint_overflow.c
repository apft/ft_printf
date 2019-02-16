/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_add_bigint_overflow.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:43:31 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 12:54:15 by apion            ###   ########.fr       */
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

	a = (t_bigint){4, {256, 0, 0, BIGINT_BLOCK_MAX_VALUE, 0}};
	b = (t_bigint){4, {42, 789, 0, 2, 0}};
	bigint_init_null(&result);
	expected = (t_bigint){4, {256 + 42,
	   789,
	   0,
	   (BIGINT_BLOCK_MAX_VALUE + 2) - BIGINT_BLOCK_MAX_VALUE - 1,
	   BIGINT_OVERFLOW}};

	bigint_add(&result, &a, &b);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &b, &result, &expected, diff);	
	return (diff);
}
