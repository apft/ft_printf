/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_bigint_add_int_overflow.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:18:13 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 17:19:28 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_int_overflow(void)
{
	t_bigint	a;
	int			n;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){4, {0xffffffff, 0xffffffff, 0xffffffff, 0xfffffff0, 0}};
	n = 42;
	bigint_init_null(&result);
	expected = (t_bigint){4, {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, BIGINT_OVERFLOW}};

	bigint_add_int(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
