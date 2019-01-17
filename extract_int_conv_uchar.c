/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_uchar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:56:46 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 19:18:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static unsigned char	extract_arg(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

static unsigned int		get_size(unsigned char value, char *base)
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

static void				fill_str(unsigned char value, char *base, char *str)
{
}

unsigned int			extract_int_conv_uchar(va_list ap, t_specs *specs,
							char *base, char *str)
{
	unsigned char	value;

	value = extract_arg(ap);
	specs->width = get_size(value, base);
	if (str)
		fill_str(value, base, str);
	return (specs->width);
}
