/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:54 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 13:15:43 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "utils.h"
#include "test_bigint_mult_self.h"

int		test_bigint_mult_self_int(t_bigint *a, unsigned int n, t_bigint *expected, int test_overflow)
{
	int			diff;
	t_bigint	a_cpy;

	bigint_copy(&a_cpy, a);
	bigint_mult_int(a, a, n);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(a);
	else
		diff = bigint_cmp(a, expected);
	if (diff)
		print_diff_bigint(&a_cpy, 0, a, expected, diff);
	return (diff ? 1 : 0);
}

int		test_bigint_mult_self_by_basis(t_bigint *a, t_bigint *b, t_bigint *expected, int test_overflow)
{
	int			diff;
	t_bigint	a_cpy;

	bigint_copy(&a_cpy, a);
	bigint_mult_by_basis(a, a, b);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(a);
	else
		diff = bigint_cmp(a, expected);
	if (diff)
		print_diff_bigint(&a_cpy, b, a, expected, diff);
	return (diff ? 1 : 0);
}

int		test_bigint_mult_self(t_bigint *a, t_bigint *b, t_bigint *expected, int test_overflow)
{
	int			diff;
	t_bigint	a_cpy;

	bigint_copy(&a_cpy, a);
	bigint_mult(a, a, b);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(a);
	else
		diff = bigint_cmp(a, expected);
	if (diff)
		print_diff_bigint(&a_cpy, b, a, expected, diff);
	return (diff ? 1 : 0);
}

int		test_bigint_mult_self_launcher(void)
{
	t_unit_test		*test_list;

	test_list = 0;
	add_test(&test_list, "Multiply self: bigint * 1 (easy)", &test_bigint_mult_self_int_one_easy);
	add_test(&test_list, "Multiply self: bigint * 1 (medium)", &test_bigint_mult_self_int_one_medium);
	add_test(&test_list, "Multiply self: bigint * 1 (medium2)", &test_bigint_mult_self_int_one_medium2);
	add_test(&test_list, "Multiply self small: bigint * 42 (easy)", &test_bigint_mult_self_int_small_easy);
	add_test(&test_list, "Multiply self small: bigint * 10 (medium)", &test_bigint_mult_self_int_small_medium);
	add_test(&test_list, "Multiply self small: bigint * 16 (carry)", &test_bigint_mult_self_int_small_carry);
	add_test(&test_list, "Multiply self small: bigint * 16 (overflow)", &test_bigint_mult_self_int_small_overflow);
	add_test(&test_list, "Multiply self medium: bigint * 0xfffff (easy)", &test_bigint_mult_self_int_medium_easy);
	add_test(&test_list, "Multiply self medium: bigint * 0xffff (medium)", &test_bigint_mult_self_int_medium_medium);
	add_test(&test_list, "Multiply self medium: bigint * 0x10000 (carry)", &test_bigint_mult_self_int_medium_carry);
	add_test(&test_list, "Multiply self medium: bigint * 0x100 (overflow)", &test_bigint_mult_self_int_medium_overflow);
	add_test(&test_list, "Multiply self: bigint * basis (1)", &test_bigint_mult_self_by_basis_1);
	add_test(&test_list, "Multiply self: bigint * basis (2)", &test_bigint_mult_self_by_basis_2);
	add_test(&test_list, "Multiply self: bigint * basis (3)", &test_bigint_mult_self_by_basis_3);
	add_test(&test_list, "Multiply self: bigint * basis (4)", &test_bigint_mult_self_by_basis_4);
	add_test(&test_list, "Multiply self: bigint * basis (overflow)", &test_bigint_mult_self_by_basis_overflow);
	add_test(&test_list, "Multiply self: bigint * bigint (easy)", &test_bigint_mult_self_easy);
	add_test(&test_list, "Multiply self: bigint * bigint (medium)", &test_bigint_mult_self_medium);
	add_test(&test_list, "Multiply self: bigint * bigint (carry)", &test_bigint_mult_self_carry);
	add_test(&test_list, "Multiply self: bigint * bigint (overflow)", &test_bigint_mult_self_overflow);
	return (launch_tests("BIGINT MULTIPLY SELF", &test_list));
}
