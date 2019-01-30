/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 17:25:07 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"
#include "filter.h"
#include "filler.h"
#include "extractor.h"

#include <stdio.h>
static double		extract_arg(va_list ap)
{
	return (va_arg(ap, double));
}

static int		get_size(unsigned long n)
{
	int		size;

	size = 1;
	while (n >>= 4)
		++size;
//	printf("arg_size= %d\n", size);
	return (size);
}

static int		get_size_exp(int exp)
{
	int		size;

	size = 1;
	while (exp /= 10)
		++size;
//	printf("exp_size= %d\n", size);
	return (size);
}

static void		fill_str(union u_double *value, char *b, char *str, t_specs *specs)
{
	unsigned long	n;
	int				i;
	int				j;
	int				exp;

	i = filler(str, specs, FILL_START);
	*(str + i++) = value->field.exp ? '1' : '0';
	if (value->field.frac || (specs->flags & PRECISION && specs->precision))
		*(str + i++) = '.';
	n = value->field.frac;
	i += n ? get_size(n) : 0;
	j = 0;
	while (n)
	{
		*(str + i - (++j)) = *(b + (n & 0b1111UL));
		n >>= 4;
	}
	exp = value->field.exp - FLOAT_EXP_BIAS;
	*(str + i++) = 'p';
	*(str + i++) = value->field.exp && exp < 0 ? '-' : '+';
	j = value->field.exp ? get_size_exp(exp) : 0;
	if (!value->field.exp)
		*(str + i) = '0';
	while (j--)
	{
		*(str + i + j) = '0' + (exp < 0 ? -(exp % 10) : exp % 10);
		exp /= 10;
	}
}

int				extract_float_conv_hex(va_list ap, t_specs *specs, char *str)
{
	union u_double	value;
	char			*base;

	value.n = extract_arg(ap);
	if (value.field.exp == FLOAT_EXP_MAX)
	{
		if (!value.field.frac && !value.field.sign)
			return (handle_str_conv("inf", specs, str));
		if (!value.field.frac && value.field.sign)
			return (handle_str_conv("-inf", specs, str));
		if (value.field.frac)
			return (handle_str_conv("nan", specs, str));
	}
	base = get_base(specs->type);
//	dbg_print(value);
	specs->is_neg = value.field.sign;
	specs->flags |= PREFIX;
	specs->type |= specs->type & FLOAT_HEXA ? HEXA : HEXA_C;
	specs->width_arg = 1 + specs->is_neg;
	if (value.field.frac || (specs->flags & PRECISION && specs->precision))
		specs->width_arg += 1;
	specs->width_arg += value.field.frac ? get_size(value.field.frac) : 0;
	specs->width_arg += 2 + get_size_exp(value.field.exp - FLOAT_EXP_BIAS);
	filter_specs(specs);
//	print_specs(specs);
//	printf("sign\texp\n%d\t%d\n", value.field.sign, value.field.exp - FLOAT_EXP_BIAS);
	if (str)
		fill_str(&value, base, str, specs);
	return (1);
}
