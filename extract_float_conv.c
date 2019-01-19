/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:11 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 22:33:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

union	u_double
{
	double	n;
	unsigned long	l;
};

static void		print_bits_int(int l)
{
	int		i;
	int		j;

	printf("%d\n", l);
	i = 10;
	while (i--)
		printf("%hhu", (l >> i) & 1);
	printf("\n");
}
static void		print_bits(long l)
{
	int		i;
	int		j;

	printf("%ld\n", l);
	i = 64;
	while (i--)
		printf("%hhu", (l >> i) & 1);
	printf("\n");
}

static double		extract_arg(va_list ap)
{
	return (va_arg(ap, double));
}

static int		extract_exp(unsigned long n)
{
	int		e;
	int		i;

	n <<= 1;
	e = 0;
	i = 64;
	while (i > 53)
		e = e * 2 + ((n >> i--) & 1);
	printf("%u\n", e);
	return (e - 1023);
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

static void		fill_str(int value, char *base, char *str, t_specs *specs)
{
	int		b;
	int		i;
	int		j;

	b = 0;
	while (*(base + b))
		b++;
	i = 0;
	i += fill_start(str, specs);
	j = specs->width_arg;
	while (j--)
	{
		*(str + i + j) = *(base + (specs->is_neg ? -(value % b) : value % b));
		value /= b;
	}
	i += specs->width_arg;
	fill_end(str + i, i, specs);
}

int				extract_float_conv(va_list ap, t_specs *specs, char *str)
{
	union u_double	value;
	int				sign;
	int				exp;
	int				frac;

	value.n = extract_arg(ap);
	print_bits(value.l);
	sign = -((value.l >> 63) & 1);
	exp = ((value.l << 1UL) >> 54) - 1023;
	printf("sign\texp\n%d\t%d\n", sign, exp);
	//printf("%f\n%llu\n", value.n, value.n);
//	specs->is_neg = value < 0;
//	specs->width_arg = get_size(value, base) - specs->is_neg;
//	if (!value && (specs->flags & PREFIX) && (specs->flags & (HEXA | HEXA_C)))
//		specs->flags ^= PREFIX;
//	if (!value && (specs->flags & PRECISION) && !specs->precision)
//		specs->width_arg -= 1;
//	filter_specs(specs);
//	if (str)
//		fill_str(value, base, str, specs);
	return (1);
}
