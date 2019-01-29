/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:57:52 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 18:37:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filter.h"
#include "filler.h"

static char		*extract_arg(va_list ap)
{
	return (va_arg(ap, char *));
}

static int		get_size(char *value)
{
	int		i;

	i = 0;
	while (*(value + i))
		i++;
	return (i);
}

static void		fill_str(char *value, char *str, t_specs *specs)
{
	int		i;
	int		j;

	i = 0;
	i += filler(str, specs, FILL_START);
	j = 0;
	if (specs->flags & PRECISION)
	{
		while (j < specs->precision && *(value + j))
			*(str + i++) = *(value + j++);
	}
	else
	{
		while (*(value + j))
			*(str + i++) = *(value + j++);
	}
	filler(str + i, specs, i);
}

int				handle_str_conv(char *value, t_specs *specs, char *str)
{
	if (!value)
		value = NULL_STR;
	specs->width_arg = get_size(value);
	filter_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}

int				extract_str_conv(va_list ap, t_specs *specs, char *str)
{
	return (handle_str_conv(extract_arg(ap), specs, str));
}
