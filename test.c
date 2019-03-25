/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:43:41 by apion             #+#    #+#             */
/*   Updated: 2019/03/25 16:00:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
	int	ret;
	int	ret_va;

	ret = ft_printf("%.La|%.10a|%.3a|%.30a\n", (long double)0xf.aep-1,0x1.1p-1060, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	ret_va = printf("%.La|%.10a|%.3a|%.30a\n", (long double)0xf.aep-1,0x1.1p-1060, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%.1150a|%.1150a\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
//	ret_va = printf("%.1150a|%.1150a\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
	ret = ft_printf("%.1a|%-.2La|%+La\n", DBL_MAX, (long double)0xe.fffp23, 12.847e451L);
	ret_va = printf("%.1a|%-.2La|%+La\n", DBL_MAX, (long double)0xe.fffp23, 12.847e451L);
	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
	ret = ft_printf("%La|%-La|%+La\n", LDBL_MIN, LDBL_MAX, 12.847e451L);
	ret_va = printf("%La|%-La|%+La\n", LDBL_MIN, LDBL_MAX, 12.847e451L);
	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%a|%-a|%+a|% a|%#a|%0a\n", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
//	ret = ft_printf("%-+8.14a|%- 8.14a|%-#8.14a|%-08.14a|%-+#8.14a|%-+ #08.14a\n", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
//	ret_va = printf("%-+8.14a|%- 8.14a|%-#8.14a|%-08.14a|%-+#8.14a|%-+ #08.14a\n", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%a|%-a|%+a|% a|%#a|%0a\n", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
//	ret_va = printf("%a|%-a|%+a|% a|%#a|%0a\n", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%.70a|%a\n", 2347686459876.00000023457, 9048512.);
//	ret_va = printf("%.70a|%a\n", 2347686459876.00000023457, 9048512.);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("|%a|%10a|%10.a|%10.0a|%.1a|%10.2a|%10.5a|\n", 0.,0.,0.,0.,0.,0.,0.);
//	ret_va = printf("|%a|%10a|%10.a|%10.0a|%.1a|%10.2a|%10.5a|\n", 0.,0.,0.,0.,0.,0.,0.);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("|%La|%10La|%10.La|%10.0La|%.1La|%10.2La|%10.5La|\n", (long double)0.,(long double)0.,(long double)12.456,(long double)0.,(long double)0.,(long double)0.,(long double)0.);
//	ret_va = printf("|%La|%10La|%10.La|%10.0La|%.1La|%10.2La|%10.5La|\n", (long double)0.,(long double)0.,(long double)12.456,(long double)0.,(long double)0.,(long double)0.,(long double)0.);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("|%La|%10La|%10.La|%10.0La|%.1La|%10.2La|%10.5La|\n", (long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.);
//	ret_va = printf("|%La|%10La|%10.La|%10.0La|%.1La|%10.2La|%10.5La|\n", (long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.,(long double)0.);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%.12La|%La\n", (long double)2347686459876.00000023457, (long double)9048512.);
//	ret_va = printf("%.12La|%La\n", (long double)2347686459876.00000023457, (long double)9048512.);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%#032.10b|%#B\n", 1342387, 123);
//	ret_va = printf("%.10d|%d\n", 1, 123);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%.100f|%f\n", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201);
//	ret_va = printf("%.100f|%f\n", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%f|%f|%f|%f|%f", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201);
//	ret_va = printf("%f|%f|%f|%f|%f", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%.2147483656f", 1.0);
//	ret_va = printf("%.2147483656f", 1.0);
//	printf("\nret = %d, ret_va = %d\n", ret, ret_va);

//	ret = ft_printf("%#14.10x\n", LONG_MIN-1);	
//	ret_va = printf("%#14.10x\n", LONG_MIN-1);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%f\n", 12.847e161);	
//	ret_va = printf("%f\n", 12.847e161);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%f\n", 12.847e161);	
//	ret_va = printf("%f\n", 12.847e161);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%Lf\n", 12.847e27L);	
//	ret_va = printf("%Lf\n", 12.847e27L);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%Lf\n", 12.847e28L);	
//	ret_va = printf("%Lf\n", 12.847e28L);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%f\n", 12.847e28);	
//	ret_va = printf("%f\n", 12.847e28);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret_va = printf("%.2000Lf\n", (long double)DBL_MIN);	
//	ret = ft_printf("%.2000Lf\n", (long double)DBL_MIN);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	ret_va = printf("%Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%Lf|%-Lf|%+Lf|% Lf|%#Lf|%0Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	ret_va = printf("%Lf|%-Lf|%+Lf|% Lf|%#Lf|%0Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("%Lf|%-Lf|%+Lf|% Lf|%#Lf|%0Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	ret_va = printf("%Lf|%-Lf|%+Lf|% Lf|%#Lf|%0Lf\n", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%o|%-#8.10o|%-#8.4o|\n", 0, 0, 0);	
//	ret_va = printf("tru: |%o|%-#8.10o|%-#8.4o|\n", 0, 0, 0);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%o|%#8.10o|%#8.4o|\n", 0, 0, 0);	
//	ret_va = printf("tru: |%o|%#8.10o|%#8.4o|\n", 0, 0, 0);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%o|%-#8.10o|%-#8.4o|\n", 1, 1, 1);	
//	ret_va = printf("tru: |%o|%-#8.10o|%-#8.4o|\n", 1, 1, 1);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%-#.F|\n", 5.5);	
//	ret_va = printf("tru: |%-#.F|\n", 5.5);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%-#*.*d|\n", -15, 4, 42);	
//	ret_va = printf("tru: |%-#*.*d|\n", -15, 4, 42);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%- 14.42f|\n", NAN);	
//	ret_va = printf("tru: |%- 14.42f|\n", NAN);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |%0 14.42f|\n", NAN);	
//	ret_va = printf("tru: |%0 14.42f|\n", NAN);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
//	ret = ft_printf("ft_: |% .42f|\n", NAN);	
//	ret_va = printf("tru: |% .42f|\n", NAN);	
//	printf("ret = %d, ret_va = %d\n", ret, ret_va);
	return (0);
}
