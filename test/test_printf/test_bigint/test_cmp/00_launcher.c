/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:26:53 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 15:56:17 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_cmp.h"

int		test_bigint_cmp_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	add_test(&test_list, "Cmp: bigint == bigint", &test_bigint_cmp_equal);
	add_test(&test_list, "Cmp: bigint < bigint", &test_bigint_cmp_inf);
	add_test(&test_list, "Cmp: bigint > bigint", &test_bigint_cmp_sup);
	add_test(&test_list, "Cmp length: bigint < bigint", &test_bigint_cmp_length_inf);
	add_test(&test_list, "Cmp length: bigint > bigint", &test_bigint_cmp_length_sup);
	add_test(&test_list, "Cmp: (bigint)0 == (bigint)0", &test_bigint_cmp_equal_null);
	return (launch_tests("TEST BIGINT CMP", &test_list));
}
