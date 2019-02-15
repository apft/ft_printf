/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:23:11 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 12:15:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bigint.h"

void	print_diff(char *format, int length_return, int length_expected,
					char *expected, char *result, int diff)
{
	int		length_diff;
	char	*color;
	char	*no_color;

	length_diff = length_return != length_expected;
	color = length_diff ? "\e[33m" : "";
	no_color = length_diff ? "\e[0m" : "";
	printf("\e[1;4mformat:\e[0m %s\n", format);
	printf("  --size ret : %s%d%s\n", color, length_return, no_color);
	printf("  --size exp : %d\n", length_expected);
	printf("  --str ret  : %s\n", result);
	printf("  --str exp  : %s\n", expected);
	printf("  --diff cmp : %d\n", diff);
}

void	print_diff_bigint(t_bigint *a, t_bigint *b, t_bigint *result,
	   					t_bigint *expected, int diff)
{
	printf("cmp(result, expected) = %d\n", diff);
	printf("a\tb\n");
	print_bigint(a);
	print_bigint(b);
	printf("result\texpected\n");
	print_bigint(result);
	print_bigint(expected);
}
