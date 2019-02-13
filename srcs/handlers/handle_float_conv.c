/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/02/13 14:59:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"
#include "filler.h"

#include <stdio.h>
static int	get_size(double value, char *base)
{
	int		size;
	int		b;

	b = 0;
	while (*(base + b))
		b++;
	size = 1 + (value < 0);
	while (value /= b)
		size++;
	return (size);
}

static void	fill_str(union u_double *value, char *str, t_specs *specs)
{
	double	a;
	int		p;
	int		i;
	int		digit;

	(void)str;
	(void)specs;
	a = value->field.sign ? -value->field.sign * value->type_dbl : value->type_dbl;
	p = 0;
	while ((a /= 10) > 1.0)
		p++;
	a *= 10;
	printf("n= %f\npow= %d\na= %f\n", value->type_dbl, p, a);
	i = 0;
	while (a > 0.0 && i < 15)
	{
		digit = (int)a;
		printf("%c", '0' + (char)digit);
		a -= digit;
		a *= 10.0;
		++i;
	}
	printf("\n");
	get_size(2.3, "01");
}

int			handle_float_conv(union u_double *value, t_specs *specs, char *str)
{
	int				sign;
	int				exp;

	sign = (value->type_long >> 63) & 1;
	exp = ((value->type_long << 1UL) >> 53) - 1023;
	printf("sign\texp\n%d\t%d\n", sign, exp);
	printf("sign\texp\n%d\t%d\n", value->field.sign, value->field.exp - 1023);
	if (specs->flags & PRECISION && !specs->precision)
		specs->precision = 1;
	if ((specs->type & FLOAT) && !(specs->flags & PRECISION))
		specs->precision = 6;
	//printf("%f\n%llu\n", value->n, value->n);
//	specs->is_neg = value < 0;
//	specs->width_arg = get_size(value, base) - specs->is_neg;
//	if (!value && (specs->flags & PREFIX) && (specs->type & (HEXA | HEXA_C)))
//		specs->flags ^= PREFIX;
//	if (!value && (specs->flags & PRECISION) && !specs->precision)
//		specs->width_arg -= 1;
//	filter_specs(specs);
	if (str)
		fill_str(&value, str, specs);
	return (1);
}
