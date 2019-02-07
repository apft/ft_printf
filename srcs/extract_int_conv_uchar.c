/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_uchar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:00:17 by apion             #+#    #+#             */
/*   Updated: 2019/02/07 17:26:33 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filter.h"
#include "filler.h"

static unsigned char	extract_arg(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

static int				get_size(unsigned char value, char *base)
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

static void				fill_str(unsigned char value, char *base, char *str,
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

int						extract_int_conv_uchar(va_list ap, t_specs *specs,
							char *str)
{
	unsigned char	value;
	char			*base;

	value = extract_arg(ap);
	base = get_base(specs->type);
	specs->is_neg = value < 0;
	specs->width_arg = get_size(value, base);
	if (!value && (specs->flags & PREFIX) && (specs->type & (HEXA | HEXA_C)))
		specs->flags ^= PREFIX;
	if (!value && (((specs->flags & PRECISION) && !specs->precision)
				|| ((specs->type & OCTAL) && (specs->flags & PREFIX))))
		specs->width_arg = 0;
	filter_specs(specs);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
