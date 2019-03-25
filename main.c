/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:43:41 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 21:55:17 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "float_pf.h"

union u_dbl
{
	double	dbl;
	unsigned long	n;
};

int		main(void)
{
	int		ret;
	int		ret_ft;

	ret = printf("%*.d\n", -10, 42);
	ret_ft = ft_printf("%*.d\n", -10, 42);
	printf("ret:    %d\nret_ft: %d\n", ret, ret_ft);
	ret = printf("%*f\n", -10, 42.0);
	ret_ft = ft_printf("%*f\n", -10, 42.0);
	printf("ret:    %d\nret_ft: %d\n", ret, ret_ft);
	ret = printf("%*5.d\n", 10, 42);
	ret_ft = ft_printf("%*5.d\n", 10, 42);
	printf("ret:    %d\nret_ft: %d\n", ret, ret_ft);
	ret = printf("%*.*d\n", 10, 42, -342);
	ret_ft = ft_printf("%*.*d\n", 10, 42, -342);
	printf("ret:    %d\nret_ft: %d\n", ret, ret_ft);

//	printf("%.a\n", 0x5.45p-3);
//	printf("%.300a\n", 0x5.45p-3);
//	ft_printf("%.300a\n", 0x5.45p-3);
	double ld = -INFINITY;
	printf("%.200f\n", ld);
	ft_printf("%.200f\n", ld);
	printf("%.200F\n", ld);
	ft_printf("%.200F\n", ld);

	union u_double value;
//	value.type_ll = 1ULL;
//	value.type_long_dbl = 10e243 + 234;
//	value.type_ll = 1ULL;
	value.type_long_dbl = 0x1.fffffffffffffffbp-16383L; 
	printf("%La\n", value.type_long_dbl);
	printf("%La\n", 0x8p-16448L);
	ft_printf("long a: %La\n", 0x8p-16448L);
//	ft_printf("%.16448Lf\n", value.type_long_dbl);
//	ft_printf("%.1080f\n", value.type_dbl);
	printf("%10.Lf\n%Lf\n", (long double)-0.0, (long double)-42.0);
	printf("%10.Lf\n", (long double)42.0);
	printf("%10.Lf\n%Lf\n", 42.0, 34);

	
	return (0);
}
