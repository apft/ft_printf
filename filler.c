/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:22:07 by apion             #+#    #+#             */
/*   Updated: 2019/01/18 18:05:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	fill_max(int a, int b)
{
	return (a < b ? b : a);
}

static int	fill_prefix(char *str, t_specs *specs)
{
	int	i;

	i = 0;
	if (specs->is_neg)
		*(str + i++) = '-';
	if (specs->flags & PLUS)
		*(str + i++) = '+';
	if (specs->flags & SPACE)
		*(str + i++) = ' ';
	if (specs->flags & PREFIX)
		*(str + i++) = '0';
	if ((specs->flags & PREFIX) && (specs->type & HEXA))
		*(str + i++) = 'x';
	if ((specs->flags & PREFIX) && (specs->type & HEXA_C))
		*(str + i++) = 'X';
	return (i);
}

static int		fill_char(char *str, int size, char c)
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
		i += fill_char(str + i, specs->precision - specs->width_arg, '0');
	return (i);
}

static int		fill_start_normal(char *str, t_specs *specs)
{
	int		i;

	i = 0;
	if (specs->flags & PAD)
	{
		i += fill_prefix(str + i, specs);
		i += fill_char(str + i, specs->width - i - specs->width_arg, '0');
	}
	else
	{
		i += fill_char(str + i,
				specs->width - specs->width_prefix
				- fill_max(specs->width_arg, specs->precision),
				' ');
		i += fill_prefix(str + i, specs);
		if (specs->flags & PRECISION)
			i += fill_char(str + i, specs->precision - specs->width_arg, '0');
	}
	return (i);
}

int				fill_start(char *str, t_specs *specs)
{
	if (specs->flags & LEFT)
		return (fill_start_left(str, specs));
	return (fill_start_normal(str, specs));
}

int				fill_end(char *str, int start, t_specs *specs)
{
	if (specs->flags & LEFT)
		return (fill_char(str, specs->width - start, ' '));
	return (0);
}
