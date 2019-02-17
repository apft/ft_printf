/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:55:13 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 12:13:16 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_utils.h"

int		test_bigint_utils_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	add_test(&test_list, "Is overflow: true", &test_bigint_is_overflow);
	add_test(&test_list, "Is overflow: false", &test_bigint_is_overflow_false);
	add_test(&test_list, "Is underflow: true", &test_bigint_is_underflow);
	add_test(&test_list, "Is underflow: false", &test_bigint_is_underflow_false);
	return (launch_tests("BIGINT UTILS", &test_list));
}
