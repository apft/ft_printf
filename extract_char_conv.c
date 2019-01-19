/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_char_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:57:52 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 12:10:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static unsigned char	extract_arg(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

static void				fill_str(unsigned char value, char *str, t_specs *specs)
{
	int		i;

	i = 0;
	i += fill_start(str, specs);
	*(str + i++) = value;
	fill_end(str + i, i, specs);
}

int						extract_char_conv(va_list ap, t_specs *specs, char *str)
{
	unsigned char	value;

	value = extract_arg(ap);
	specs->width_arg = 1;
	filter_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}
