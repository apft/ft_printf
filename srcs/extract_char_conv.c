/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_char_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:57:52 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 17:39:03 by apion            ###   ########.fr       */
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

static void				fill_str(unsigned char value, char *str, t_specs *specs)
{
	int		i;

	i = 0;
	i += filler(str, specs, FILL_START);
	*(str + i++) = value;
	filler(str + i, specs, i);
}

int						handle_char_conv(unsigned char value, t_specs *specs,
							char *str)
{
	specs->width_arg = 1;
	filter_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}

int						extract_char_conv(va_list ap, t_specs *specs, char *str)
{
	return (handle_char_conv(extract_arg(ap), specs, str));
}
