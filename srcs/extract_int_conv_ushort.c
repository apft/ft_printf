/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_ushort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:00:17 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 18:31:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filter.h"
#include "filler.h"

static unsigned short	extract_arg(va_list ap)
{
	return ((unsigned short)va_arg(ap, int));
}

static int				get_size(unsigned short value, char *base)
{
	int		size;
	int		b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1;
	while (value /= b)
		size++;
	return (size);
}

static void				fill_str(unsigned short value, char *base, char *str,
							t_specs *specs)
{
	int		b;
	int		i;
	int		j;

	b = 0;
	while (*(base + b))
		b++;
	i = 0;
	i += filler(str, specs, FILL_START);
	j = specs->width_arg;
	while (j--)
	{
		*(str + i + j) = *(base + value % b);
		value /= b;
	}
	i += specs->width_arg;
	filler(str + i, specs, i);
}

int						extract_int_conv_ushort(va_list ap, t_specs *specs,
							char *str)
{
	unsigned short	value;
	char			*base;

	value = extract_arg(ap);
	base = get_base(specs->type);
	specs->width_arg = get_size(value, base);
	if (!value && (specs->flags & PREFIX) && (specs->flags & (HEXA | HEXA_C)))
		specs->flags ^= PREFIX;
	if (!value && (specs->flags & PRECISION) && !specs->precision)
		specs->width_arg -= 1;
	filter_specs(specs);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
