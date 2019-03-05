/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:00:05 by apion             #+#    #+#             */
/*   Updated: 2019/03/05 22:01:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "utils.h"
#include "bigint.h"
#include "test_bigint_mult.h"

int		test_bigint_mult_int(t_bigint *a, unsigned int n, t_bigint *expected)
{
	t_bigint	result;
	int			diff;

	bigint_init_null(&result);
	bigint_mult_int(&result, a, n);
	diff = bigint_cmp(&result, expected);
	if (diff)
		print_diff_bigint(a, 0, &result, expected, diff);	
	return (diff ? 1 : 0);
}

int		test_bigint_mult_launcher(void)
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
	add_test(&test_list, "Multiply medium: bigint * 0xff (overflow)", &test_bigint_mult_int_medium_overflow);
	//add_test(&test_list, "Multiply: bigint * INT_MAX", &test_bigint_mult_int_max);
	//add_test(&test_list, "Multiply: bigint * 0", &test_bigint_mult_int_null);
	return (launch_tests("BIGINT MULTIPLY", &test_list));
}
