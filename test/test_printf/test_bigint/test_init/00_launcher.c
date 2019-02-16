/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:06:12 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 11:51:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_init.h"

int		test_bigint_init_launcher(void)
{
	t_unit_test *test_list;

	test_list = 0;
	add_test(&test_list, "init null", &test_bigint_init_null);
	add_test(&test_list, "init int: n = 42", &test_bigint_init_int);
	add_test(&test_list, "init int: n = 0", &test_bigint_init_int_null);
	add_test(&test_list, "init int: n = int_max", &test_bigint_init_int_max);
	return (launch_tests("TEST BIGINT INIT", &test_list));
}
