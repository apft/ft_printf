/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:54 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:35:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "utils.h"
#include "test_bigint_mult_bigint.h"

int		test_bigint_mult_int(t_bigint *a, unsigned int n, t_bigint *expected, int test_overflow)
{
	t_bigint	result;
	int			diff;

	bigint_init_null(&result);
	bigint_mult_int(&result, a, n);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(&result);
	else
		diff = bigint_cmp(&result, expected);
	if (diff)
		print_diff_bigint(a, 0, &result, expected, diff);	
	return (diff ? 1 : 0);
}

int		test_bigint_mult_by_basis(t_bigint *a, t_bigint *b, t_bigint *expected, int test_overflow)
{
	t_bigint	result;
	int			diff;

	bigint_init_null(&result);
	bigint_mult_by_basis(&result, a, b);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(&result);
	else
		diff = bigint_cmp(&result, expected);
	if (diff)
		print_diff_bigint(a, b, &result, expected, diff);	
	return (diff ? 1 : 0);
}

int		test_bigint_mult(t_bigint *a, t_bigint *b, t_bigint *expected, int test_overflow)
{
	t_bigint	result;
	int			diff;

	bigint_init_null(&result);
	bigint_mult(&result, a, b);
	if (test_overflow == TEST_OVERFLOW)
		diff = !bigint_is_overflow(&result);
	else
		diff = bigint_cmp(&result, expected);
	if (diff)
		print_diff_bigint(a, b, &result, expected, diff);	
	return (diff ? 1 : 0);
}

int		test_bigint_mult_bigint_launcher(void)
{
	t_unit_test		*test_list;

	test_list = 0;
	add_test(&test_list, "Multiply: bigint * 1 (easy)", &test_bigint_mult_int_one_easy);
	add_test(&test_list, "Multiply: bigint * 1 (medium)", &test_bigint_mult_int_one_medium);
	add_test(&test_list, "Multiply: bigint * 1 (medium2)", &test_bigint_mult_int_one_medium2);
	add_test(&test_list, "Multiply small: bigint * 42 (easy)", &test_bigint_mult_int_small_easy);
	add_test(&test_list, "Multiply small: bigint * 10 (medium)", &test_bigint_mult_int_small_medium);
	add_test(&test_list, "Multiply small: bigint * 16 (carry)", &test_bigint_mult_int_small_carry);
	add_test(&test_list, "Multiply small: bigint * 16 (overflow)", &test_bigint_mult_int_small_overflow);
	add_test(&test_list, "Multiply medium: bigint * 0xfffff (easy)", &test_bigint_mult_int_medium_easy);
	add_test(&test_list, "Multiply medium: bigint * 0xffff (medium)", &test_bigint_mult_int_medium_medium);
	add_test(&test_list, "Multiply medium: bigint * 0x10000 (carry)", &test_bigint_mult_int_medium_carry);
	add_test(&test_list, "Multiply medium: bigint * 0x100 (overflow)", &test_bigint_mult_int_medium_overflow);
	add_test(&test_list, "Multiply: bigint * basis (1)", &test_bigint_mult_by_basis_1);
	add_test(&test_list, "Multiply: bigint * basis (2)", &test_bigint_mult_by_basis_2);
	add_test(&test_list, "Multiply: bigint * basis (3)", &test_bigint_mult_by_basis_3);
	add_test(&test_list, "Multiply: bigint * basis (4)", &test_bigint_mult_by_basis_4);
	add_test(&test_list, "Multiply: bigint * basis (overflow)", &test_bigint_mult_by_basis_overflow);
	add_test(&test_list, "Multiply: bigint * bigint (easy)", &test_bigint_mult_easy);
	add_test(&test_list, "Multiply: bigint * bigint (medium)", &test_bigint_mult_medium);
	add_test(&test_list, "Multiply: bigint * bigint (carry)", &test_bigint_mult_carry);
	add_test(&test_list, "Multiply: bigint * bigint (overflow)", &test_bigint_mult_overflow);
	return (launch_tests("BIGINT MULTIPLY", &test_list));
}
