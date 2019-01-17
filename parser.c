/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:00:42 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 23:54:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

void	print_specs(t_specs *specs)
{
	printf("-\t+\t^\t#\t0\thh\th\tl\tll\twidth\tprec\tneg\ttype\n");
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			specs->flags & LEFT,
			specs->flags & PLUS,
			specs->flags & SPACE,
			specs->flags & PREFIX,
			specs->flags & PAD,
			specs->flags & CHAR,
			specs->flags & SHORT,
			specs->flags & LONG,
			specs->flags & LONG_LONG,
			specs->width,
			specs->precision,
			specs->is_neg,
			specs->type);
}

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
	specs->width = parse_nbr(f);
}

static void	parse_precision(char **f, t_specs *specs)
{
	++(*f);
	specs->flags |= PRECISION;
	if (specs->flags & PAD)
		specs->flags ^= PAD;
	specs->precision = parse_nbr(f);
}

static int	parse_type(char *f, t_specs *specs, va_list ap, char *str)
{
	if ((*f == 'd' || *f == 'i') && (specs->type = INT))
		return (extract_int_conv(ap, specs, "0123456789", str));
	if (*f == 'o' && (specs->type = OCTAL))
		return (extract_int_conv_u(ap, specs, "01234567", str));
	if (*f == 'u' && (specs->type = UINT))
		return (extract_int_conv_u(ap, specs, "0123456789", str));
	if (*f == 'x' && (specs->type = HEXA))
		return (extract_int_conv_u(ap, specs, "0123456789abcdef", str));
	if (*f == 'X' && (specs->type = HEXA_CAP))
		return (extract_int_conv_u(ap, specs, "0123456789ABCDEF", str));
	if (*f == 'f' && (specs->type = FLOAT))
		return (FLOAT);
	if (*f == 'c' && (specs->type = T_CHAR))
		return (0);
	if (*f == 's' && (specs->type = STRING))
		return (0);
	if (*f == 'p' && (specs->type = POINTER))
		return (0);
	if (*f == '%' && (specs->type = PERCENT))
		return (0);
	return (0);
}

int		parse_specs(char **f, t_specs *specs, va_list ap, char *str)
{
	++(*f);
	while (**f && !parse_type(*f, specs, ap, str))
	{
		specs->flags |= (**f == '-') ? LEFT : 0;
		specs->flags |= (**f == '+') ? PLUS : 0;
		specs->flags |= (**f == ' ' && !(specs->flags & PLUS)) ? SPACE : 0;
		specs->flags |= (**f == '#') ? PREFIX : 0;
		specs->flags |= (**f == '0' && !(specs->flags & LEFT)
				&& !(specs->precision)) ? PAD : 0;
		specs->flags |= (**f == 'h' && *((*f) + 1) == 'h') ? CHAR : 0;
		specs->flags |= (!(specs->flags & CHAR)
				&& **f == 'h' && *((*f) + 1) != 'h') ? SHORT : 0;
		specs->flags |= (**f == 'l' && *((*f) + 1) != 'l') ? LONG : 0;
		specs->flags |= (**f == 'L' || **f == 'q'
			|| (**f == 'l' && *((*f) + 1) == 'l')) ? LONG_LONG : 0;
		if (**f >= '1' && **f <= '9')
			parse_width(f, specs);
		if (**f == '.')
			parse_precision(f, specs);
		if (**f)
			++(*f);
	}
	print_specs(specs);
	int width = 0;
	width += (specs->type & INT)
					&& (specs->flags & PLUS || specs->flags & SPACE) ? 1 : 0;
	width += (specs->flags & PREFIX) ? 1 : 0;
	width += (specs->type & HEXA || specs->type & HEXA_CAP) ? 1 : 0;
	width += specs->width_arg < specs->precision ? specs->precision : specs->width_arg;
	if (specs->width < width)
		specs->width = width;
	printf("size= %d\n", specs->width);
	return (1);
}
