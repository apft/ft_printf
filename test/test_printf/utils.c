/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:23:11 by apion             #+#    #+#             */
/*   Updated: 2019/02/05 13:55:35 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_diff(char *format, char *expected, char *result)
{
	printf("format: %s\n", format);
	printf("  result  : %s\n", result);
	printf("  expected: %s\n", expected);
}
