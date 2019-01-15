/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:23:35 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 19:01:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

unsigned int	size_int(va_list ap, char *b, t_specs *specs)
{
	if (specs->flags & CHAR)
		return (get_size_char(extract_arg_char(ap), b));
//	if (specs->flags & SHORT)
//		return (get_size_short(extract_arg_short(ap), b));
//	if (specs->flags & LONG)
//		return (get_size_long(extract_arg_long(ap), b));
//	if (specs->flags & LONG_LONG)
//		return (get_size_long_long(extract_arg_long_long(ap), b));
	return (get_size_int(extract_arg_int(ap), b));
}

unsigned int	size_uint(va_list ap, char *b, t_specs *specs)
{
	if (specs->flags & CHAR)
		return (get_size_uchar(extract_arg_uchar(ap), b));
//	if (specs->flags & SHORT)
//		return (get_size_ushort(extract_arg_ushort(ap), b));
//	if (specs->flags & LONG)
//		return (get_size_ulong(extract_arg_ulong(ap), b));
//	if (specs->flags & LONG_LONG)
//		return (get_size_ulong_long(extract_arg_ulong_long(ap), b));
//	if (specs->flags & SIZE_T)
//		return (get_size_size_t(extract_arg_size_t(ap), b));
	return (get_size_uint(extract_arg_uint(ap), b));
}
