/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:00:42 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 19:50:26 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

void	print_specs(t_specs *specs)
{
	printf("-\t%u\n", specs->flags & LEFT);
	printf("+\t%u\n", specs->flags & PLUS);
	printf("^\t%u\n", specs->flags & SPACE);
	printf("#\t%u\n", specs->flags & PREFIX);
	printf("0\t%u\n", specs->flags & PAD);
	printf("hh\t%u\n", specs->flags & CHAR);
	printf("h\t%u\n", specs->flags & SHORT);
	printf("l\t%u\n", specs->flags & LONG);
	printf("ll\t%u\n", specs->flags & LONG_LONG);
	printf("width\t%u\n", specs->flags & WIDTH);
	printf("prec\t%u\n", specs->flags & PRECISION);
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
	specs->flags |= PRECISION;
	specs->precision = parse_nbr(f);
}

static int	is_type(char *f, t_specs *specs, va_list ap)
{
	ft_print_mem(f, ft_strlen(f));
	if ((*f == 'd' || *f == 'i') && (specs->type = INT))
		return (size_int(ap, "0123456789", specs));
	if (*f == 'o' && (specs->type = OCTAL))
		return (size_uint(ap, "01234567", specs));
	if (*f == 'u' && (specs->type = UINT))
		return (size_uint(ap, "0123456789", specs));
	if (*f == 'x' && (specs->type = HEXA))
		return (size_uint(ap, "0123456789abcdef", specs));
	if (*f == 'X' && (specs->type = HEXA_CAP))
		return (size_uint(ap, "0123456789ABCDEF", specs));
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

int		parse_specs(char **f, t_specs *specs, va_list ap)
{
	int		ret;

	ret = 0;
	++(*f);
	while (**f && !(ret = is_type(*f, specs, ap)))
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
			parse_precision(++f, specs);
		if (**f)
			++(*f);
	}
	print_specs(specs);
	specs->size = ret;
	specs->size += (specs->type & INT)
					&& (specs->flags & PLUS || specs->flags & SPACE) ? 1 : 0;
	specs->size += (specs->flags & PREFIX) && (specs->type & OCTAL) ? 1 : 0;
	specs->size += (specs->flags & PREFIX)
		&& (specs->type & HEXA || specs->type & HEXA_CAP) ? 2 : 0;
	if ((specs->flags & WIDTH) && specs->size < specs->width)
		specs->size = specs->width;
	printf("size= %d\n", specs->size);
	return (1);
}
