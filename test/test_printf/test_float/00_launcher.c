/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:49:21 by apion             #+#    #+#             */
/*   Updated: 2019/03/18 18:04:01 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_float.h"

int		test_float_launcher()
{
	int		n;

	n = 0;
//	n += test_extract_float_conv_launcher();
//	n += test_extract_float_conv_hexa_launcher();
//	n += test_extract_float_conv_subnormal_launcher();
	n += test_extract_float_conv_limits_launcher();
	n += test_extract_float_conv_long_dbl_launcher();
	return (n);
}
