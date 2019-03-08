/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_mult.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:55:19 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 12:24:48 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult_self.h"

int			test_bigint_mult_self_easy(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){2, {42, 4350, 0, 0, 0}};
	b = (t_bigint){2, {254661, 13, 0, 0, 0}};
	expected = (t_bigint){3, {10695762, 1107775896, 13*4350, 0, 0}};
	return (test_bigint_mult_self(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_self_medium(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){2, {42, 3456, 0, 0, 0}};
	b = (t_bigint){3, {234, 0, 12, 0, 0}};
	expected = (t_bigint){4, {42*234, 234*3456, 42*12, 12*3456, 0}};
	return (test_bigint_mult_self(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_self_carry(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){2, {0x2a, 0xed4f2, 0, 0, 0}};
	b = (t_bigint){3, {0x16, 0x100000, 342, 0, 0}};
	expected = (t_bigint){4, {
		0x2a*0x16,
		0x2a00000 + 0xed4f2*0x16,
		0x2a*342 + 0x4f200000,
		0xed + 342*0xed4f2, 
		0}};
	return (test_bigint_mult_self(&a, &b, &expected, !TEST_OVERFLOW));
}

int			test_bigint_mult_self_overflow(void)
{
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;

	a = (t_bigint){2, {0x235, 0xc408, 0, 0, 0}};
	b = (t_bigint){3, {0, 0x1049, 0x2e35d8b, 0, 0}};
	expected = (t_bigint){4, {0, 0, 0, 42, BIGINT_OVERFLOW}};
	return (test_bigint_mult_self(&a, &b, &expected, TEST_OVERFLOW));
}
