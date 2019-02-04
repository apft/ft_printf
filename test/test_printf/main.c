/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:51:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/04 15:33:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int		main(void)
{
	int		n;

	n = 0;
	n += test_extract_int_conv_launcher();
//	n += test_extract_int_conv_char_launcher();
//	n += test_extract_int_conv_short_launcher();
//	n += test_extract_int_conv_int_launcher();
//	n += test_extract_int_conv_long_launcher();
//	n += test_extract_int_conv_long_long_launcher();
//	n += test_extract_int_conv_u_launcher();
//	n += test_extract_int_conv_uchar_launcher();
//	n += test_extract_int_conv_ushort_launcher();
//	n += test_extract_int_conv_uint_launcher();
//	n += test_extract_int_conv_ulong_launcher();
//	n += test_extract_int_conv_ulong_long_launcher();
//	n += test_extract_char_conv_launcher();
//	n += test_extract_str_conv_launcher();
//	n += test_extract_percent_conv_launcher();
//	n += test_extract_pointer_conv_launcher();
//	n += test_extract_float_conv_launcher();
//	n += test_extract_float_conv_hex_launcher();
	if (n)
		return (1);
	return (0);
}
