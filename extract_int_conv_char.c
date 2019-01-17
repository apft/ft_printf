/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:56:16 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 18:56:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static char			extract_arg(va_list ap)
{
	return ((char)va_arg(ap, int));
}

static unsigned int	get_size(char value, char *base)
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

static void			fill_str(char value, char *base, char *str)
{
}

unsigned int		extract_int_conv_char(va_list ap, t_specs *specs,
							char *base, char *str)
{
	char	value;

	value = extract_arg(ap);
	specs->width = get_size(value, base);
	if (str)
		fill_str(value, base, str);
	return (specs->width);
}
