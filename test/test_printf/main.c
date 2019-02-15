/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:51:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 12:48:37 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int		main(void)
{
	int		n;

	n = 0;
//	n += test_extract_int_conv_launcher();
//	n += test_extract_float_conv_hex_launcher();
//	n += test_extract_str_char_conv_launcher();
//	n += test_extract_ptr_percent_conv_launcher();
	n += test_bigint_launcher();
	printf("TOTAL ERROR= %d\n", n);
	if (n)
		return (1);
	return (0);
}
