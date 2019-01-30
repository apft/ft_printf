/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_pointer_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:29:48 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 18:33:45 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "extractor.h"

int		extract_pointer_conv(va_list ap, t_specs *specs, char *str)
{
	specs->flags &= ~(MOD_HH | MOD_H | MOD_LL);
	specs->flags |= PREFIX | MOD_L;
	specs->type |= HEXA;
	return (extract_int_conv_u(ap, specs, str));
}