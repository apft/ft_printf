/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_ptr_percent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:38:24 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 18:38:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_ptr_percent.h"

int		test_extract_ptr_percent_conv_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	return (launch_tests("TEST POINTER PERCENT %p %%", &test_list));
}
