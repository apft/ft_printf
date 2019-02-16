/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:58:18 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:32:16 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_shift_left.h"

int		test_bigint_shift_left_launcher(void)
{
	t_unit_test *test_list;

	test_list = 0;
	add_test(&test_list, "shift left 0", &test_bigint_shift_left_null);
	add_test(&test_list, "shift left 1", &test_bigint_shift_left_one);
	add_test(&test_list, "shift left 23", &test_bigint_shift_left_pos);
	add_test(&test_list, "shift left 1 block", &test_bigint_shift_left_block);
	add_test(&test_list, "shift left 39 (> 1 block)", &test_bigint_shift_left_few_blocks);
	add_test(&test_list, "shift left overflow", &test_bigint_shift_left_overflow);
	return (launch_tests("TEST BIGINT SHIFT LEFT", &test_list));
}
