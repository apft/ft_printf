/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:51:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 11:31:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int		main(void)
{
	int		n;

	n = 0;
//	n += test_extract_int_conv_launcher();
	n += test_extract_float_conv_hex_launcher();
	if (n)
		return (1);
	return (0);
}
