/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:20:32 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 19:17:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

static void		test_float_hexa(double d)
{
	char *f;

	f = "%a\n";
	printf("\nstr: %snbr: %f\n", f, d);
	ft_printf(f, d, d, d, d, d, d, d, d);
	printf("printf:\t");
	printf(f, d, d, d, d, d, d, d, d);
}

int		main(void)
{
	ft_printf("%f\n", 0.);
	ft_printf("%f\n", -1.);
	ft_printf("%f\n", 1.);
	ft_printf("%f\n", 2.);
	ft_printf("%f\n", 0.875);
	ft_printf("%f\n", 5.2/2);
	printf("%f\n", 5.2/2);
	ft_printf("%.0f\n", 151.5);
	ft_printf("%.0f\n", 451.5);
	printf("%.0f\n", 451.5);
	ft_printf("%.0f\n", 51.5);
	printf("%.0f\n", 51.5);
	ft_printf("%.0f\n", -68.5);
	printf("%.0f\n", -68.5);
	printf("%.0f\n", 32.5);
	printf("%.0f\n", 23.5);
	printf("%f\n", -5./0);
	test_float_hexa(0);
	test_float_hexa(1);
	test_float_hexa(2);
	test_float_hexa(32);
	test_float_hexa(-32);
	test_float_hexa(1.42);
	test_float_hexa(0.42);
	test_float_hexa(6.42);
	test_float_hexa(.0625);
//	ft_printf("%8.7d\n", 123456);
//	printf("%8.7d\n", 123456);
//	ft_printf("%.0f\n", 151.5);
//	ft_printf("%.0f\n", 451.5);
//	printf("%.0f\n", 451.5);
//	ft_printf("%.0f\n", 51.5);
//	printf("%.0f\n", 51.5);
//	ft_printf("%.0f\n", -68.5);
//	printf("%.0f\n", -68.5);
//	printf("%.0f\n", 32.5);
//	printf("%.0f\n", 23.5);
//	printf("%f\n", -5./0);
	return (0);
}
