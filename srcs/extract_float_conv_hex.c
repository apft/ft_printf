/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 15:14:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"
#include "filter.h"
#include "filler.h"

#include <stdio.h>
static double		extract_arg(va_list ap)
{
	return (va_arg(ap, double));
}

static int		get_size(unsigned long n)
{
	int		size;

	size = 1;
	while (n <<= 4)
		++size;
	return (size);
}

static int		get_size_exp(int exp)
{
	int		size;

	size = 1;
	while (exp /= 10)
		++size;
	printf("exp_size= %d\n", size);
	return (size);
}

static void		fill_str(union u_double *value, char *b, char *str, t_specs *specs)
{
	unsigned long	a;
	int				i;
	int				j;
	int				exp;

	a = value->field.frac;
	exp = value->field.exp - FLOAT_EXP_BIAS;
	i = 0;
	i += filler(str, specs, FILL_START);
	j = get_size(a);
	while (j-- && a)
	{
		printf("%c-", *(b + a % 16));
		*(str + i + j) = *(b + a % 16);
		a >>= 4;
	}
	*(str + i++) = value->field.exp ? '1' : '0';
	if (value->field.frac)
		*(str + i++) = '.';
	i += get_size(value->field.frac) - j;
	*(str + i++) = 'p';
	*(str + i++) = exp < 0 ? '-' : '+';
	j = get_size_exp(exp);
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
	base = get_base(specs->type);
	printf("b= %s\n", base);
//	dbg_print(value);
	specs->is_neg = value.field.sign;
	specs->flags |= PREFIX;
	specs->type |= specs->type & FLOAT_HEXA ? HEXA : HEXA_C;
	specs->width_arg = specs->is_neg;
	specs->width_arg += get_size(value.field.frac);
	specs->width_arg += 2 + get_size_exp(value.field.exp- FLOAT_EXP_BIAS);
	filter_specs(specs);
//	print_specs(specs);
	printf("sign\texp\n%d\t%d\n", value.field.sign, value.field.exp- FLOAT_EXP_BIAS);
	if (str)
		fill_str(&value, base, str, specs);
	return (1);
}
