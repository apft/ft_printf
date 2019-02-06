/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:23:11 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 11:29:35 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_diff(char *format, int ret, int exp, char *expected, char *result)
{
	int		err;

	err = ret != exp;
	printf("\e[1;4mformat:\e[0m %s\n", format);
	printf("  --size ret : %s%d%s\n", err ? "\e[33m" : "", ret, err ? "\e[0m" : "");
	printf("  --size exp : %d\n", exp);
	printf("  --str ret  : %s\n", result);
	printf("  --str exp  : %s\n", expected);
}
