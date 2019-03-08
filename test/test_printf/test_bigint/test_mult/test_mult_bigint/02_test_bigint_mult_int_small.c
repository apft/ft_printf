/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_mult_int_small.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:06:41 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:40:18 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult_bigint.h"

int			test_bigint_mult_int_small_easy(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	n = 42;
	expected = (t_bigint){1, {1764, 0, 0, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_small_medium(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){3, {13987, 42, 42, 0, 0}};
	n = 10;
	expected = (t_bigint){3, {139870, 420, 420, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_small_carry(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){4, {0xff0f, 0, 0xffffffff, 0, 0}};
	n = 16;
	expected = (t_bigint){4, {0xff0f0, 0, 0xfffffff0, 0xf, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_small_overflow(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){4, {34235, 0, 0, 0xffffffff, 0}};
	n = 16;
	expected = (t_bigint){4, {547760, 0, 0, 0xfffffff0, BIGINT_OVERFLOW}};
	return (test_bigint_mult_int(&a, n, &expected, TEST_OVERFLOW));
}
