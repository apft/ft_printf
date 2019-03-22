/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:37:13 by apion             #+#    #+#             */
/*   Updated: 2019/03/22 19:13:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		clear_flags(t_specs *specs, int flags)
{
	if (specs->flags & flags)
		specs->flags &= ~flags;
}

static int	compute_width_float_hexa(t_specs *specs)
{
	specs->width_arg = specs->width_prefix + 1
		+ (specs->precision || (specs->flags & FLOAT_FORCE_POINT) ? 1 : 0)
		+ specs->precision + specs->width_suffix;
	return (pf_max(specs->width_min, specs->width_arg));
}

static int	compute_width_float(t_specs *specs)
{
	if (specs->type & (FLOAT_HEXA | FLOAT_HEXA_C))
		return (compute_width_float_hexa(specs));
	return (pf_max(specs->width_min, specs->width_prefix + specs->width_arg));
}

static int	compute_width(t_specs *specs)
{
	int		width_print;

	if (specs->is_neg || specs->flags & (PLUS | SPACE))
		specs->width_prefix += 1;
	if (specs->flags & PREFIX)
		specs->width_prefix += 1;
	if ((specs->flags & PREFIX)
			&& (specs->type & (HEXA | HEXA_C | FLOAT_HEXA | FLOAT_HEXA_C)))
		specs->width_prefix += 1;
	if ((specs->type & OCTAL) && (specs->flags & PREFIX)
			&& (!specs->width_arg || ((specs->flags & PRECISION)
					&& specs->width_arg < specs->precision)))
	{
		clear_flags(specs, PREFIX);
		specs->width_prefix = 0;
	}
	if ((specs->type & (FLOAT | FLOAT_C | FLOAT_HEXA | FLOAT_HEXA_C))
			&& !(specs->type & STRING))
		return (compute_width_float(specs));
	width_print = specs->width_prefix;
	if ((specs->type & STRING) && (specs->flags & PRECISION))
		width_print += pf_min(specs->precision, specs->width_arg);
	else
		width_print += pf_max(specs->precision, specs->width_arg);
	return (pf_max(specs->width_min, width_print));
}

void		filter_specs(t_specs *specs)
{
	if (specs->type & (INT | UINT | CHAR | STRING | PERCENT))
		clear_flags(specs, PREFIX);
	if (((specs->flags & PAD) && (specs->flags & LEFT))
		|| ((specs->type & (INT | OCTAL | UINT | HEXA | HEXA_C))
			&& (specs->flags & PRECISION)))
		clear_flags(specs, PAD);
	if (specs->type & (OCTAL | UINT | HEXA | HEXA_C | CHAR | PERCENT))
		clear_flags(specs, PLUS | SPACE);
	if ((specs->type & STRING) && !(specs->type & (FLOAT | FLOAT_C)))
		clear_flags(specs, PLUS | SPACE);
	if (specs->flags & PLUS)
		clear_flags(specs, SPACE);
	if (specs->is_neg)
		clear_flags(specs, SPACE | PLUS);
	if ((specs->type & OCTAL) && (specs->flags & PREFIX) && !specs->precision)
	{
		specs->flags |= PRECISION;
		specs->precision = 1;
	}
	if (specs->type & (CHAR | PERCENT))
	{
		clear_flags(specs, PRECISION);
		specs->precision = 0;
	}
	specs->width = compute_width(specs);
}
