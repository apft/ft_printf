/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:06:05 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 19:01:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

unsigned int	extract_arg_uint(va_list ap)
{
	return (va_arg(ap, unsigned int));
}

unsigned int	get_size_uint(unsigned int n, char *base)
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

void		fill_str_uint(char *str, unsigned int beg, char *b, t_specs *specs)
{
}
