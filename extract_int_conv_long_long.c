/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_long_long.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:10:11 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 19:23:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static long long		extract_arg(va_list ap)
{
	return (va_arg(ap, unsigned long long));
}

static unsigned int		get_size(long long value, char *base)
{
	unsigned int	size;
	unsigned int	b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1 + (value < 0);
	while (value /= b)
		size++;
	return (size);
}

static void				fill_str(long long value, char *base, char *str)
{
}

unsigned int			extract_int_conv_long_long(va_list ap, t_specs *specs,
								char *base, char *str)
{
	long long	value;

	value = extract_arg(ap);
	specs->width = get_size(value, base);
	if (str)
		fill_str(value, base, str);
	return (specs->width);
}
