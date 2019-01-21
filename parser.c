/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:00:42 by apion             #+#    #+#             */
/*   Updated: 2019/01/24 18:28:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static int	parse_nbr(char **str)
{
	int		n;

	n = 0;
	while (**str >= '0' && **str <= '9')
		n = 10 * n + (*((*str)++) - '0');
	--(*str);
	return (n);
}

static void	parse_width(char **f, t_specs *specs)
{
	specs->flags |= WIDTH;
	specs->width_min = parse_nbr(f);
}

static void	parse_precision(char **f, t_specs *specs)
{
	++(*f);
	specs->flags |= PRECISION;
	specs->precision = parse_nbr(f);
}

int		is_valid(char *c)
{
	int		i;

	i = 0;
	while (VALID_CHAR[i])
		if (c == VALID_CHAR[i++])
			return (1);
	return (0);
}
static int	parse_type(char *f, t_specs *specs, va_list ap, char *str)
{
	if (!is_valid(*f))
		return (extract_char_conv(*f, specs, str));
	if ((*f == 'd' || *f == 'i') && (specs->type = INT))
		return (extract_int_conv(ap, specs, BASE_DEC, str));
	if (*f == 'o' && (specs->type = OCTAL))
		return (extract_int_conv_u(ap, specs, BASE_OCT, str));
	if (*f == 'u' && (specs->type = UINT))
		return (extract_int_conv_u(ap, specs, BASE_DEC, str));
	if (*f == 'x' && (specs->type = HEXA))
		return (extract_int_conv_u(ap, specs, BASE_HEXA, str));
	if (*f == 'X' && (specs->type = HEXA_C))
		return (extract_int_conv_u(ap, specs, BASE_HEXA_C, str));
	if (*f == 'f' && (specs->type = FLOAT))
		return (extract_float_conv(ap, specs, str));
	if (*f == 'c' && (specs->type = CHAR))
		return (extract_char_conv((unsigned char)va_arg(ap, int), specs, str));
	if (*f == 's' && (specs->type = STRING))
		return (extract_str_conv(ap, specs, str));
	if (*f == 'p' && (specs->type = POINTER))
		return (extract_pointer_conv(ap, specs, BASE_HEXA, str));
	if (*f == '%' && (specs->type = PERCENT))
		return (extract_percent_conv(specs, str));
	return (0);
}

int			parse_specs(char **f, t_specs *specs, va_list ap, char *str)
{
	++(*f);
	while (**f && !parse_type(*f, specs, ap, str))
	{
		specs->flags |= (**f == '-') ? LEFT : 0;
		specs->flags |= (**f == '+') ? PLUS : 0;
		specs->flags |= (**f == ' ') ? SPACE : 0;
		specs->flags |= (**f == '#') ? PREFIX : 0;
		specs->flags |= (**f == '0') ? PAD : 0;
		specs->flags |= (**f == 'h' && *((*f) + 1) == 'h') ? MOD_HH : 0;
		specs->flags |= (!(specs->flags & MOD_HH)
				&& **f == 'h' && *((*f) + 1) != 'h') ? MOD_H : 0;
		specs->flags |= (**f == 'l' && *((*f) + 1) == 'l') ? MOD_LL : 0;
		specs->flags |= (!(specs->flags & MOD_LL)
				&& **f == 'l' && *((*f) + 1) != 'l') ? MOD_L : 0;
		specs->flags |= (**f == 'L') ? MOD_LD : 0;
		if (**f >= '1' && **f <= '9')
			parse_width(f, specs);
		if (**f == '.')
			parse_precision(f, specs);
		if (**f)
			++(*f);
	}
	return (1);
}
