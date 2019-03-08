/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:33 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:24:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_add_bigint.h"

int		test_bigint_add_bigint_launcher(void)
{
	t_unit_test *test_list;

	test_list = 0;
	add_test(&test_list, "Add: bigint + bigint", &test_bigint_add_bigint);
	add_test(&test_list, "Add self: bigint + bigint", &test_bigint_add_bigint_self);
	add_test(&test_list, "Add null: bigint + (bigint)0", &test_bigint_add_bigint_null);
	add_test(&test_list, "Add carry: bigint + bigint", &test_bigint_add_bigint_carry);
	add_test(&test_list, "Add overflow: bigint + bigint", &test_bigint_add_bigint_overflow);
	add_test(&test_list, "Add: bigint + int", &test_bigint_add_int);
	add_test(&test_list, "Add null: bigint + 0", &test_bigint_add_int_null);
	add_test(&test_list, "Add carry: bigint + int", &test_bigint_add_int_carry);
	add_test(&test_list, "Add overflow: bigint + int", &test_bigint_add_int_overflow);
	return (launch_tests("TEST BIGINT ADD", &test_list));
}
