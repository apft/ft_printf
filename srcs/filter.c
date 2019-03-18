/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:37:13 by apion             #+#    #+#             */
/*   Updated: 2019/03/18 14:42:48 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdio.h>
void		print_specs(t_specs *specs)
{
	printf("-\t+\t^\t#\t0\t.\thh\th\tl\tll\tL\tw_min\tprec\tw_arg\tw_pref\tw_suff\twidth\tneg\tdbl.\tdbl->10\ttype\n");
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			!!(specs->flags & LEFT),
			!!(specs->flags & PLUS),
			!!(specs->flags & SPACE),
			!!(specs->flags & PREFIX),
			!!(specs->flags & PAD),
			!!(specs->flags & PRECISION),
			!!(specs->flags & MOD_HH),
			!!(specs->flags & MOD_H),
			!!(specs->flags & MOD_L),
			!!(specs->flags & MOD_LL),
			!!(specs->flags & MOD_LD),
			specs->width_min,
			specs->precision,
			specs->width_arg,
			specs->width_prefix,
			specs->width_suffix,
			specs->width,
			specs->is_neg,
			!!(specs->flags & FLOAT_FORCE_POINT),
			!!(specs->flags & FLOAT_ROUND_TEN),
			specs->type);
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
		specs->width_prefix = 0;
	if ((specs->type & (FLOAT | FLOAT_HEXA | FLOAT_HEXA_C))
			&& !(specs->type & STRING))
		return (compute_width_float(specs));
	width_print = specs->width_prefix;
	if ((specs->type & STRING) && (specs->flags & PRECISION))
		width_print += pf_min(specs->precision, specs->width_arg);
	else
		width_print += pf_max(specs->precision, specs->width_arg);
	return (pf_max(specs->width_min, width_print));
}

void		clear_flags(t_specs *specs, int flags)
{
	if (specs->flags & flags)
		specs->flags &= ~flags;
}

void		filter_specs(t_specs *specs)
{
	if (specs->type & (INT | UINT | CHAR | STRING | PERCENT))
		clear_flags(specs, PREFIX);
	if ((specs->type & (INT | OCTAL | UINT | HEXA | HEXA_C))
			&& (specs->flags & PRECISION))
		clear_flags(specs, PAD);
	if ((specs->flags & PAD) && (specs->flags & LEFT))
		clear_flags(specs, PAD);
	if (specs->type & (OCTAL | UINT | HEXA | HEXA_C | CHAR | PERCENT))
		clear_flags(specs, PLUS | SPACE);
	if ((specs->type & STRING) && !(specs->type & FLOAT))
		clear_flags(specs, PLUS | SPACE);
	if (specs->flags & PLUS)
		clear_flags(specs, SPACE);
	if (specs->is_neg)
		clear_flags(specs, SPACE | PLUS);
	if ((specs->type & OCTAL) && (specs->flags & PREFIX) && !specs->precision)
		specs->precision = 1;
	if (specs->type & (CHAR | PERCENT))
	{
		clear_flags(specs, PRECISION);
		specs->precision = 0;
	}
	specs->width = compute_width(specs);
}
