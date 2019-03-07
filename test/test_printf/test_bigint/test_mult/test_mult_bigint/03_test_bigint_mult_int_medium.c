/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_bigint_mult_int_medium.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:27:19 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:40:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult_bigint.h"

int			test_bigint_mult_int_medium_easy(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	n = 0xfffff;
	expected = (t_bigint){1, {44040150, 0, 0, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_medium_medium(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){3, {13987, 42, 42, 0, 0}};
	n = 0xffff;
	expected = (t_bigint){3, {916638045, 2752470, 2752470, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_medium_carry(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){4, {0xfb, 0xa, 0xffffffff, 0, 0}};
	n = 0x10000;
	expected = (t_bigint){4, {0xfb0000, 0xa0000, 0xffff0000, 0xffff, 0}};
	return (test_bigint_mult_int(&a, n, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_int_medium_overflow(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){4, {34235, 873451, 1, 0xffffffff, 0}};
	n = 0x100;
	expected = (t_bigint){4, {8764160, 873451 * n, n, 0xffffff00, BIGINT_OVERFLOW}};
	return (test_bigint_mult_int(&a, n, &expected, TEST_OVERFLOW));
}
