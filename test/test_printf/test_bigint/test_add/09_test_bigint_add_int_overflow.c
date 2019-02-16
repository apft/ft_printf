/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_bigint_add_int_overflow.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:18:13 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 12:55:46 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_int_overflow(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		result;
	t_bigint		expected;
	int				diff;

	n = 0xff;
	a = (t_bigint){4, {
		BIGINT_BLOCK_MAX_VALUE,
		BIGINT_BLOCK_MAX_VALUE,
		BIGINT_BLOCK_MAX_VALUE,
		BIGINT_BLOCK_MAX_VALUE,
		0}};
	n += 2;
	bigint_init_null(&result);
	expected = (t_bigint){4, {
		(BIGINT_BLOCK_MAX_VALUE + n) - BIGINT_BLOCK_MAX_VALUE - 1,
		0,
		0,
		0,
		BIGINT_OVERFLOW}};

	bigint_add_int(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
