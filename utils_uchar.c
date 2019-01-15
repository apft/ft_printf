/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:06:05 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 17:57:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

unsigned char		extract_arg_uchar(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

unsigned int	get_size_uchar(unsigned char n, char *base)
{
	unsigned int	size;
	unsigned int	b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1;
	while (n /= b)
		size++;
	return (size);
}

void		fill_str_uchar(char *str, unsigned int beg, char *b, t_specs *specs)
{
}
