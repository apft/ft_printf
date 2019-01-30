/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:01:41 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 13:58:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include "utils_float.h"

static void	test_a(double f)
{
	char			*format;
	union u_double	value;

	value.n = f;
	format = "|%a|%10a|%10.a|%10.0a|%10.2a|%10.5a|%20.10a|%45.40a|\n";
	printf("\n%f\n", value.n);
	printf("%s", format);
	printf(format , f, f, f, f, f, f, f, f);
	dbg_print(value);
}

static void	test_lf(long double f)
{
	printf("|%10Lf|%10.0Lf|%10.2Lf|%10.5Lf|%20.10Lf|%45.40Lf|\n", f, f, f, f, f, f);
}

static void	test(double f)
{
	printf("|%10f|%10.0f|%10.2f|%10.5f|%20.10f|%45.40f|\n", f, f, f, f, f, f);
}

int		main(void)
{
	double			f;
	union u_double	value;

	printf("sizeof union: %zd bits\n", 8 * sizeof(union u_double));
	test_a(0);
	test_a(-0);
	test_a(-0.0);
	test_a(1);
	test_a(-1.0);
	test_a(1.5);
	test_a(0.2);
	printf("%f\n", 1.42);
	printf("%a\n", 0x1.92p+1);
	printf("%f\n", 0x1.92p+1);
	printf("%a\n", 0xc9p-6);
	printf("%f\n", 0xc9p-6);
	test_a(2.0);
	test_a(3.0);
	test_a(16.0);
	test_a(53.0);
	test_a(-4242.0);
//	test(4503599627370496.9);
//	test(0x1.0p52);
//	test(0x1.000001p52);
//	test(36028797018963968);
//	test(36028797018963970);
//	test_a(2.30258509);
//	test(151.5);
//	test(451.5);
//	test(51.5);
//	test(-68.5);
//	test(32.5);
//	test(23.5);
//	test(1.0/3);
//	test(1.42);
//	test(1.419999999999);
//	test(1.419999999998);
//	test(1.418888888888);
//	test_lf(1.0/3);
//	test_lf(1.42);
//	test_lf(1.419999999999);
//	test_lf(1.419999999998);
//	test_lf(1.418888888888);
//	printf("%Lf\n", LDBL_MAX);
//	printf("%LA\n", LDBL_MAX);
//	printf("%.15La\n", LDBL_MAX);
//	printf("%.4f\n", 5.1);
//	printf("%.18f\n", 5.1);
	return (0);
}
