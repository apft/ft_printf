/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 19:07:33 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filler.h"

#include <stdio.h>
union	u_double
{
	double	n;
	unsigned long	l;
	struct
	{
		unsigned long	mantissa:52;
		unsigned int	exponent:11;
		unsigned int	sign:1;
	};
};

static void		print_bits_int(int l)
{
	int		i;

	printf("%d\n", l);
	i = 11;
	while (i--)
		printf("%hhu", (unsigned char)((l >> i) & 1));
	printf("\n");
}
static void		print_bits(long l)
{
	int		i;

	printf("%ld\n", l);
	i = 64;
	while (i--)
		printf("%hhu", (unsigned char)((l >> i) & 1));
	printf("\n");
}

static double		extract_arg(va_list ap)
{
	return (va_arg(ap, double));
}

static int		get_size(double value, char *base)
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

static void		fill_str(union u_double *value, char *str, t_specs *specs)
{
	double	a;
	int		p;
	int		i;
	int		digit;

	(void)str;
	(void)specs;
	a = value->sign ? -value->sign * value->n : value->n;
	p = 0;
	while ((a /= 10) > 1.0)
		p++;
	a *= 10;
	printf("n= %f\npow= %d\na= %f\n", value->n, p, a);
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

int				extract_float_conv(va_list ap, t_specs *specs, char *str)
{
	union u_double	value;
	int				sign;
	int				exp;

	value.n = extract_arg(ap);
	print_bits(value.l);
	print_bits(value.mantissa);
	print_bits_int(value.sign);
	print_bits_int(value.exponent);
	sign = (value.l >> 63) & 1;
	exp = ((value.l << 1UL) >> 53) - 1023;
	printf("sign\texp\n%d\t%d\n", sign, exp);
	printf("sign\texp\n%d\t%d\n", value.sign, value.exponent - 1023);
	//printf("%f\n%llu\n", value.n, value.n);
//	specs->is_neg = value < 0;
//	specs->width_arg = get_size(value, base) - specs->is_neg;
//	if (!value && (specs->flags & PREFIX) && (specs->flags & (HEXA | HEXA_C)))
//		specs->flags ^= PREFIX;
//	if (!value && (specs->flags & PRECISION) && !specs->precision)
//		specs->width_arg -= 1;
//	filter_specs(specs);
	if (str)
		fill_str(&value, str, specs);
	return (1);
}
