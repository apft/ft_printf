/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:50:00 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 17:57:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "extractor.h"

int		extract_int_conv(va_list ap, t_specs *specs, char *str)
{
	if (specs->flags & MOD_HH)
		return (extract_int_conv_char(ap, specs, str));
	if (specs->flags & MOD_H)
		return (extract_int_conv_short(ap, specs, str));
	if (specs->flags & MOD_L)
		return (extract_int_conv_long(ap, specs, str));
	if (specs->flags & MOD_LL)
		return (extract_int_conv_long_long(ap, specs, str));
	return (extract_int_conv_int(ap, specs, str));
}

int		extract_int_conv_u(va_list ap, t_specs *specs, char *str)
{
	if (specs->flags & MOD_HH)
		return (extract_int_conv_uchar(ap, specs, str));
	if (specs->flags & MOD_H)
		return (extract_int_conv_ushort(ap, specs, str));
	if (specs->flags & MOD_L)
		return (extract_int_conv_ulong(ap, specs, str));
	if (specs->flags & MOD_LL)
		return (extract_int_conv_ulong_long(ap, specs, str));
	return (extract_int_conv_uint(ap, specs, str));
}
