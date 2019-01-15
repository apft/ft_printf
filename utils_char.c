/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:06:05 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 19:19:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

char			extract_arg_char(va_list ap)
{
	return ((char)va_arg(ap, int));
}

unsigned int	get_size_char(char n, char *base)
{
	unsigned int	size;
	unsigned int	b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1 + (n < 0);
	while (n /= b)
		size++;
	return (size);
}

void		fill_str_char(char *str, unsigned int beg, char *b, t_specs *specs)
{
}
