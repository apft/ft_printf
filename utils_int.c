/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:06:05 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 18:38:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

int		extract_arg_int(va_list ap)
{
	return (va_arg(ap, int));
}

unsigned int	get_size_int(int n, char *base)
{
	unsigned int	size;
	unsigned int	b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1;
	while (n /= b)
		size++;
	printf("b: %d size: %d\n", b, size);
	return (size);
}

void		fill_str_int(char *str, unsigned int beg, char *b, t_specs *specs)
{
}
