/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:20:32 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 10:54:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static void		print_test(char *f)
{
	int			i_min = INT_MIN;
	int			i_max = INT_MAX;
	long		l_min = LONG_MIN;
	long		l_max = LONG_MAX;
	long long	ll_min = 0x1000000000000000;
	long long	ll_max = 0x7FFFFFFFFFFFFFFF;
	long long	bits = -1;

	printf("\n%s", f);
	ft_printf(f, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf(f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	ft_printf(f, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf(f, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	ft_printf(f, -123, -123, -123, -123, -123, -123, -123, -123, -123);
	printf(f, -123, -123, -123, -123, -123, -123, -123, -123, -123);
	ft_printf(f, i_max, i_max, i_max, i_max, i_max, i_max, i_max, i_max, i_max);
	printf(f, i_max, i_max, i_max, i_max, i_max, i_max, i_max, i_max, i_max);
	ft_printf(f, i_min, i_min, i_min, i_min, i_min, i_min, i_min, i_min, i_min);
	printf(f, i_min, i_min, i_min, i_min, i_min, i_min, i_min, i_min, i_min);
	ft_printf(f, l_max, l_max, l_max, l_max, l_max, l_max, l_max, l_max, l_max);
	printf(f, l_max, l_max, l_max, l_max, l_max, l_max, l_max, l_max, l_max);
	ft_printf(f, l_min, l_min, l_min, l_min, l_min, l_min, l_min, l_min, l_min);
	printf(f, l_min, l_min, l_min, l_min, l_min, l_min, l_min, l_min, l_min);
	ft_printf(f, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max);
	printf(f, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max, ll_max);
	ft_printf(f, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min);
	printf(f, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min, ll_min);
	ft_printf(f, bits, bits, bits, bits, bits, bits, bits, bits, bits);
	printf(f, bits, bits, bits, bits, bits, bits, bits, bits, bits);
}

int		main(void)
{
	ft_printf("|%c%c%c%c|\n", 'a', 'B', 0, '*');
	printf("|%c%c%c%c|\n", 'a', 'B', 0, '*');
	ft_printf("|%4c|%-11.4c|%05c|%.c|\n", 'a', 'B', 0, '*');
	printf("|%4c|%-11.4c|%05c|%.c|\n", 'a', 'B', 0, '*');
	ft_printf("%s|%5c|%s\n", "This is a string.", '\0', "hidden part...");
	printf("%s|%5c|%s\n", "This is a string.", '\0', "hidden part...");
	ft_printf("|%s|%-32s|%23.12s|%10.2s|\n", "This is another string.", "and a second one", "one more", "final one ?");
	printf("|%s|%-32s|%23.12s|%10.2s|\n", "This is another string.", "and a second one", "one more", "final one ?");
	ft_printf("|%.12s|%-13.5s|%3.12s|%3.12s|%10.s|\n", "This is another string.", "and a second one", "one more", "sdfljhgidfghoisufghskjhg", "final one ?");
	printf("|%.12s|%-13.5s|%3.12s|%3.12s|%10.s|\n", "This is another string.", "and a second one", "one more", "sdfljhgidfghoisufghskjhg", "final one ?");
	printf("%15s|%5c|%s\n", 0, '\0', "hidden part...");
//	print_test("|%5u|%5o|%5x|%5X|%#5o|%#5x|%#5X|%#10.8x|\n");
//	print_test("|%d|%.d|%.2d|%2.d|%2.1d|%+d|%-4d|\n");
//	print_test("|%5d|%-5d|%+5d|%+-5d|% 5d|%05d|%5.0d|%5.2d|%d|\n");
//	print_test("|%035d|%05.d|%-25.17d|\n");
//	print_test("|%035ld|%05.ld|%-25.17ld|\n");
//	print_test("|%ld|%.ld|%.2ld|%2.ld|%2.1ld|%+ld|%-4ld|\n");
//	print_test("|%5ld|%-5ld|%+5ld|%+-5ld|% 5ld|%05ld|%5.0ld|%5.2ld|%ld|\n");
//	print_test("|%lld|%.lld|%.2lld|%2.lld|%2.1lld|%+lld|%-4lld|\n");
//	print_test("|%5lld|%-5lld|%+5lld|%+-5lld|% 5lld|%05lld|%5.0lld|%5.2lld|%lld|\n");
//	print_test("|%035lld|%05.lld|%-25.17lld|\n");
//	print_test("|%lu|%.lu|%.2lu|%2.lu|%2.1lu|%+lu|%-4lu|\n");
//	print_test("|%llu|%.llu|%.2llu|%2.llu|%2.1llu|%+llu|%-4llu|\n");
//	print_test("|%x|%.x|%.2x|%2.x|%2.1x|%+x|%-4x|\n");
//	print_test("|%5x|%-5x|%+5x|%+-5x|% 5x|%05x|%5.0x|%5.2x|%x|\n");
//	print_test("|%035x|%05.x|%-25.17x||%#0 16.10x|\n");
//	print_test("|%X|%.X|%.2X|%2.X|%2.1X|%+X|%-4X|\n");
//	print_test("|%5X|%-5X|%+5X|%+-5X|% 5X|%05X|%5.0X|%5.2X|%X|\n");
//	print_test("|%035X|%05.X|%-25.17X|\n");
//	print_test("|%o|%.o|%.2o|%2.o|%2.1o|%+o|%-4o|\n");
//	print_test("|%5o|%-5o|%+5o|%+-5o|% 5o|%05o|%5.0o|%5.2o|%o|\n");
//	print_test("|%035o|%05.o|%-25.17o|\n");

//	ft_printf("|%05.d|\n", 0);
//	printf("|%05.d|\n", 0);
//	ft_printf("|%05.d|\n", 3);
//	printf("|%05.d|\n", 3);
//	ft_printf("|%5.4d|\n", 422);
//	printf("|%5.4d|\n", 422);
//	ft_printf("|%+5.4d|\n", 422);
//	printf("|%+5.4d|\n", 422);
//	ft_printf("|%+5.4d|\n", -422);
//	printf("|%+5.4d|\n", -422);
	ft_printf("|%+#X|%#hhx|%#-3hx|%12llX|\n", 422, 51233545, 0, 0);
	printf("|%+#X|%#hhx|%#-3hx|%12llX|\n", 422, 51233545, 0, 0);
	ft_printf("|%+d %hhu|\n", 422, 51233545);
	printf("|%+d %hhu|\n", 422, 51233545);
	ft_printf("|%+d %hhu|\n", 422, -51233545);
	printf("|%+d %hhu|\n", 422, -51233545);
//	printf("|%05.3d|\n", 12345);
//	ft_printf("|%#10.8x|\n", 42);
//	printf("|%#10.8x|\n", 42);
//	ft_printf("|%#10.9x|\n", 42);
//	printf("|%#10.9x|\n", 42);
//	ft_printf("|%#5.0x|\n", 0);
//	printf("|%#5.0x|\n", 0);
//	ft_printf("|%#5x|\n", 1);
//	printf("|%#5x|\n", 1);
//	ft_printf("|%0#5x|\n", 1);
//	printf("|%0#5x|\n", 1);
//	printf("|%05d|\n", 1);
//	printf("|%05d|\n", -1);
//	printf("|%05.3d|\n", -1);
//	printf("|%5.5d|\n", 1);
//	printf("|%5.5d|\n", -1);
//	printf("|%5.6d|\n", 1);
//	printf("|%5.6d|\n", -1);
	return (0);
}
