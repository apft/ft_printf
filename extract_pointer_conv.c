/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_pointer_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:29:48 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 14:07:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

int		extract_pointer_conv(va_list ap, t_specs *specs, char *base, char *str)
{
	specs->flags &= ~(MOD_HH | MOD_H | MOD_LL);
	specs->flags |= PREFIX | MOD_L;
	specs->type |= HEXA;
	return (extract_int_conv_u(ap, specs, base, str));
}
