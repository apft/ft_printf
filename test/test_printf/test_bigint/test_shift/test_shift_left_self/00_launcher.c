/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:58:18 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 16:36:55 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_shift_left_self.h"

int		test_bigint_shift_left_self_launcher(void)
{
	t_unit_test *test_list;

	test_list = 0;
	add_test(&test_list, "shift left_self 0", &test_bigint_shift_left_self_null);
	add_test(&test_list, "shift left_self 1", &test_bigint_shift_left_self_one);
	add_test(&test_list, "shift left_self 23", &test_bigint_shift_left_self_pos);
	add_test(&test_list, "shift left_self 1 block", &test_bigint_shift_left_self_block);
	add_test(&test_list, "shift left_self 39 (> 1 block)", &test_bigint_shift_left_self_few_blocks);
	add_test(&test_list, "shift left_self overflow", &test_bigint_shift_left_self_overflow);
	return (launch_tests("TEST BIGINT SHIFT left_self", &test_list));
}
