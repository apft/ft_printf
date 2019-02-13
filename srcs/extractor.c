/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:50:00 by apion             #+#    #+#             */
/*   Updated: 2019/02/13 00:15:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "extractor.h"
#include "handlers.h"

int		extract_int_conv(va_list ap, t_specs *specs, char *str)
{
	union u_value	value;

	value = (union u_value){0};
	if (specs->type & INT)
	{
		extract_arg_integer(ap, &value, specs->flags);
		return (handle_int_conv(&value, specs, str));
	}
	extract_arg_uinteger(ap, &value, specs->flags);
	return (handle_int_conv_u(&value, specs, str));
}

int		extract_char_conv(va_list ap, t_specs *specs, char *str)
{
	union u_value	value;

	value = (union u_value){0};
	if (specs->type & PERCENT)
		value.type_char = '%';
	else
		extract_arg_uinteger(ap, &value, MOD_HH);
	return (handle_char_conv(value.type_char, specs, str));
}

int		extract_str_conv(va_list ap, t_specs *specs, char *str)
{
	char	*value;

	value = extract_arg_str(ap);
	return (handle_str_conv(value, specs, str));
}

int		extract_pointer_conv(va_list ap, t_specs *specs, char *str)
{
	specs->flags &= ~(MOD_HH | MOD_H | MOD_LL);
	specs->flags |= PREFIX | MOD_L;
	specs->type |= HEXA;
	return (extract_int_conv(ap, specs, str));
}
