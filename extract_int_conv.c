/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_int_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:50:00 by apion             #+#    #+#             */
/*   Updated: 2019/01/18 19:00:22 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

int		extract_int_conv(va_list ap, t_specs *specs, char *base, char *str)
{
	if (specs->flags & MOD_HH)
		return (extract_int_conv_char(ap, specs, base, str));
	if (specs->flags & MOD_H)
		return (extract_int_conv_short(ap, specs, base, str));
	if (specs->flags & MOD_L)
		return (extract_int_conv_long(ap, specs, base, str));
	if (specs->flags & MOD_LL)
		return (extract_int_conv_long_long(ap, specs, base, str));
	return (extract_int_conv_int(ap, specs, base, str));
}

int		extract_int_conv_u(va_list ap, t_specs *specs, char *base, char *str)
{
	if (specs->flags & MOD_HH)
		return (extract_int_conv_uchar(ap, specs, base, str));
	if (specs->flags & MOD_H)
		return (extract_int_conv_ushort(ap, specs, base, str));
	if (specs->flags & MOD_L)
		return (extract_int_conv_ulong(ap, specs, base, str));
	if (specs->flags & MOD_LL)
		return (extract_int_conv_ulong_long(ap, specs, base, str));
	return (extract_int_conv_uint(ap, specs, base, str));
}
