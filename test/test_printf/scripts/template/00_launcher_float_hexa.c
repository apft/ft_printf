/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:06:08 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 18:50:01 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_float_hexa.h"

int		test_extract_float_conv_hex_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	return (launch_tests("TEST FLOAT %a %A", &test_list));
}