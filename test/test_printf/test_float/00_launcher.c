/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:06:08 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 11:56:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_float.h"

int		test_extract_float_launcher(void)
{
	t_unit_test	*test_list;

	test_list = 0;
	add_test(&test_list, "1 Float %f 0: 4.423547891112", &test_float_conv);
	return (launch_tests("TEST FLOAT %f", &test_list));
}
