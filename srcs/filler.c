/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:22:07 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 16:55:29 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "filler.h"

static int		fill_prefix(char *str, t_specs *specs)
{
	int	i;

	i = 0;
	if (specs->is_neg)
		*(str + i++) = '-';
	if (specs->flags & PLUS)
		*(str + i++) = '+';
	if (specs->flags & SPACE)
		*(str + i++) = ' ';
	if (specs->flags & PREFIX && !(specs->type & OCTAL && specs->width_arg
				&& specs->width_arg < specs->precision))
		*(str + i++) = '0';
	if ((specs->flags & PREFIX) && (specs->type & (HEXA | FLOAT_HEXA)))
		*(str + i++) = 'x';
	if ((specs->flags & PREFIX) && (specs->type & (HEXA_C | FLOAT_HEXA_C)))
		*(str + i++) = 'X';
	return (i);
}

static int		fill_char(char *str, char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
		*(str + i++) = c;
	return (i);
}

static int		fill_start_left(char *str, t_specs *specs)
{
	int		i;

	i = fill_prefix(str, specs);
	if ((specs->flags & PAD) || (specs->flags & PRECISION))
		i += fill_char(str + i, specs->type & PERCENT ? ' ' : '0',
				specs->precision - specs->width_arg);
	return (i);
}

static int		fill_start_normal(char *str, t_specs *specs)
{
	int		i;

	i = 0;
	if (specs->flags & PAD)
	{
		i += fill_prefix(str + i, specs);
		if (specs->type & (FLOAT | FLOAT_HEXA | FLOAT_HEXA_C))
			i += fill_char(str + i, '0', specs->width - specs->width_arg);
		else
			i += fill_char(str + i, '0', specs->width - i - specs->width_arg);
	}
	else
	{
		if ((specs->type & STRING) && (specs->flags & PRECISION))
			i += fill_char(str + i, ' ', specs->width - specs->precision);
		else if (specs->type & (FLOAT | FLOAT_HEXA | FLOAT_HEXA_C))
			i += fill_char(str + i, ' ', specs->width - specs->width_arg);
		else
			i += fill_char(str + i, ' ', specs->width - specs->width_prefix
					- pf_max(specs->width_arg, specs->precision));
		i += fill_prefix(str + i, specs);
		if ((specs->type & (STRING | PERCENT)) && (specs->flags & PRECISION))
			i += fill_char(str + i, ' ', pf_min(specs->width, specs->precision)
					- specs->width_arg);
		if (!(specs->type & (STRING | PERCENT | FLOAT | FLOAT_HEXA | FLOAT_HEXA_C)) && (specs->flags & PRECISION))
			i += fill_char(str + i, '0', specs->precision - specs->width_arg);
	}
	return (i);
}

int				filler(char *str, t_specs *specs, int start)
{
	if (start == FILL_START)
	{
		if ((specs->flags & LEFT) && (specs->type & STRING))
			return (0);
		if (specs->flags & LEFT)
			return (fill_start_left(str, specs));
		return (fill_start_normal(str, specs));
	}
	if (specs->flags & LEFT)
		return (fill_char(str, ' ', specs->width - start));
	return (0);
}
