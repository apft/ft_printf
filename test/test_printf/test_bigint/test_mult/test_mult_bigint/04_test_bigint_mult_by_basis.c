/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_mult_by_basis.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:18:09 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:40:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult_bigint.h"

int			test_bigint_mult_by_basis_1(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	b = (t_bigint){1, {1, 0, 0, 0, 0}};
	expected = (t_bigint){1, {42, 0, 0, 0, 0}};
	return (test_bigint_mult_by_basis(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_by_basis_2(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	b = (t_bigint){2, {0, 1, 0, 0, 0}};
	expected = (t_bigint){2, {0, 42, 0, 0, 0}};
	return (test_bigint_mult_by_basis(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_by_basis_3(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){2, {42, 48765, 0, 0, 0}};
	b = (t_bigint){3, {0, 0, 1, 0, 0}};
	expected = (t_bigint){4, {0, 0, 42, 48765, 0}};
	return (test_bigint_mult_by_basis(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_by_basis_4(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	b = (t_bigint){4, {0, 0, 0, 1, 0}};
	expected = (t_bigint){4, {0, 0, 0, 42, 0}};
	return (test_bigint_mult_by_basis(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_by_basis_overflow(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){3, {42, 3432, 984213, 0, 0}};
	b = (t_bigint){4, {0, 0, 0, 1, 0}};
	expected = (t_bigint){4, {0, 0, 0, 42, BIGINT_OVERFLOW}};
	return (test_bigint_mult_by_basis(&a, &b, &expected, TEST_OVERFLOW));
}
