/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_bigint_add_int_overflow.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:18:13 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:21:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_self_int_overflow(void)
{
	t_bigint		a;
	unsigned int	n;
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
	expected = (t_bigint){4, {
		(BIGINT_BLOCK_MAX_VALUE + n) - BIGINT_BLOCK_MAX_VALUE - 1,
		0,
		0,
		0,
		BIGINT_OVERFLOW}};

	bigint_add_int(&a, &a, n);
	diff = !bigint_is_overflow(&a);
	if (diff)
		print_diff_bigint(0, 0, &a, &expected, diff);	
	return (diff);
}
