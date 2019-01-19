/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:37:13 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 10:31:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_specs(t_specs *specs)
{
	printf("-\t+\t^\t#\t0\thh\th\tl\tll\tw_min\tprec\tw_arg\tw_pref\twidth\tneg\ttype\n");
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			!!(specs->flags & LEFT),
			!!(specs->flags & PLUS),
			!!(specs->flags & SPACE),
			!!(specs->flags & PREFIX),
			!!(specs->flags & PAD),
			!!(specs->flags & MOD_HH),
			!!(specs->flags & MOD_H),
			!!(specs->flags & MOD_L),
			!!(specs->flags & MOD_LL),
			specs->width_min,
			specs->precision,
			specs->width_arg,
			specs->width_prefix,
			specs->width,
			specs->is_neg,
			specs->type);
}

static int	compute_width(t_specs *specs)
{
	int 	width_print;

	if (specs->is_neg || specs->flags & (PLUS | SPACE | PREFIX))
		specs->width_prefix += 1;
	if ((specs->flags & PREFIX) && specs->type & (HEXA | HEXA_C))
		specs->width_prefix += 1;
	width_print = 0;
	if ((specs->type & STRING) && (specs->flags & PRECISION))
		width_print = pf_min(specs->precision, specs->width_arg);
	else
		width_print = pf_max(specs->precision, specs->width_arg);
	return (pf_max(specs->width_min, specs->width_prefix + width_print));
}

void	filter_specs(t_specs *specs)
{
	if ((specs->type & (CHAR | INT | POINTER | STRING | UINT))
			&& (specs->flags & PREFIX))
		specs->flags ^=  PREFIX;
	if ((specs->type & OCTAL) && (specs->flags & PREFIX))
		specs->precision += 1;
	if ((specs->type & (INT | OCTAL | UINT | HEXA | HEXA_C))
			&& (specs->flags & PAD) && (specs->flags & PRECISION))
		specs->flags ^= PAD;
	if ((specs->flags & PAD) && (specs->flags & LEFT))
		specs->flags ^= PAD;
	if ((specs->type & (OCTAL | UINT | HEXA | HEXA_C))
			&& (specs->flags & SPACE))
		specs->flags ^= SPACE;
	if ((specs->type & (OCTAL | UINT | HEXA | HEXA_C)) && (specs->flags & PLUS))
		specs->flags ^= PLUS;
	if ((specs->flags & SPACE) && (specs->flags & PLUS))
		specs->flags ^= SPACE;
	if (specs->is_neg && (specs->flags & PLUS))
		specs->flags ^= PLUS;
	if (specs->is_neg && (specs->flags & SPACE))
		specs->flags ^= SPACE;
	if ((specs->type & (CHAR | POINTER)) && (specs->flags & PRECISION))
		specs->flags ^= PRECISION;
	specs->width = compute_width(specs);
}
