/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_ulong.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:07:41 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 19:18:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static unsigned long	extract_arg(va_list ap)
{
	return (va_arg(ap, unsigned long));
}

static unsigned int		get_size(unsigned long value, char *base)
{
	unsigned int	size;
	unsigned int	b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1;
	while (value /= b)
		size++;
	return (size);
}

static void				fill_str(unsigned long value, char *base, char *str)
{
}

unsigned int			extract_int_conv_ulong(va_list ap, t_specs *specs,
							char *base, char *str)
{
	unsigned long	value;

	value = extract_arg(ap);
	specs->width = get_size(value, base);
	if (str)
		fill_str(value, base, str);
	return (specs->width);
}
