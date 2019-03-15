/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:53:28 by apion             #+#    #+#             */
/*   Updated: 2019/03/15 18:37:43 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_int.h"

int		test_extract_float_conv_limits_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	return (launch_tests("TEST INT %d %i", &test_list));
}
