/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_mult_int_one.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:50:39 by apion             #+#    #+#             */
/*   Updated: 2019/03/05 22:01:38 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult.h"

int			test_bigint_mult_int_one_easy(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){1, {42, 0, 0, 0, 0}};
	n = 1;
	expected = (t_bigint){1, {42, 0, 0, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected));
}

int			test_bigint_mult_int_one_medium(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){3, {0, 42, 42, 0, 0}};
	n = 1;
	expected = (t_bigint){3, {0, 42, 42, 0, 0}};
	return (test_bigint_mult_int(&a, n, &expected));
}

int			test_bigint_mult_int_one_medium2(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		expected;

	a = (t_bigint){4, {34235, 0, 0, 0xffffffff, 0}};
	n = 1;
	expected = (t_bigint){4, {34235, 0, 0, 0xffffffff, 0}};
	return (test_bigint_mult_int(&a, n, &expected));
}
