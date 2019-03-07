/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:33 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:31:58 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_sub_bigint.h"

int		test_bigint_sub_bigint_launcher(void)
{
	t_unit_test *test_list;

	test_list = 0;
	add_test(&test_list, "Sub: bigint - bigint", &test_bigint_sub_bigint);
	add_test(&test_list, "Sub self: bigint - bigint", &test_bigint_sub_bigint_self);
	add_test(&test_list, "Sub null: bigint - (bigint)0", &test_bigint_sub_bigint_null);
	add_test(&test_list, "Sub carry: bigint - bigint", &test_bigint_sub_bigint_carry);
	add_test(&test_list, "Sub underflow: bigint - bigint", &test_bigint_sub_bigint_underflow);
	add_test(&test_list, "Sub: bigint - int", &test_bigint_sub_int);
	add_test(&test_list, "Sub null: bigint - 0", &test_bigint_sub_int_null);
	add_test(&test_list, "Sub carry: bigint - int", &test_bigint_sub_int_carry);
	add_test(&test_list, "Sub underflow: bigint - int", &test_bigint_sub_int_underflow);
	return (launch_tests("TEST BIGINT SUB", &test_list));
}
