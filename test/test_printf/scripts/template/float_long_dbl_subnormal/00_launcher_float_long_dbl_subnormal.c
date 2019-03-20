/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_float_long_dbl_subnormal.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:53:28 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 13:59:22 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_float_long_dbl_subnormal.h"

int		test_extract_float_conv_long_dbl_subnormal_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	return (launch_tests("TEST FLOAT LONG DOUBLE SUBNORMAL %Lf", &test_list));
}
