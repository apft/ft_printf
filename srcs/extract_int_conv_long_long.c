/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_long_long.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:57:52 by apion             #+#    #+#             */
/*   Updated: 2019/02/06 23:00:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filter.h"
#include "filler.h"

static long long	extract_arg(va_list ap)
{
	return (va_arg(ap, long long));
}

static int			get_size(long long value, char *base)
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

static void			fill_str(long long value, char *base, char *str,
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
		*(str + i + j) = *(base + (specs->is_neg ? -(value % b) : value % b));
		value /= b;
	}
	i += specs->width_arg;
	filler(str + i, specs, i);
}

int					extract_int_conv_long_long(va_list ap, t_specs *specs,
						char *str)
{
	long long	value;
	char		*base;

	value = extract_arg(ap);
	base = get_base(specs->type);
	specs->is_neg = value < 0;
	specs->width_arg = get_size(value, base);
	if (!value && (specs->flags & PREFIX) && (specs->type & (HEXA | HEXA_C)))
		specs->flags ^= PREFIX;
	if (!value && (specs->flags & PRECISION) && !specs->precision)
		specs->width_arg -= 1;
	filter_specs(specs);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
