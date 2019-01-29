/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/28 18:28:41 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "utils_float.h"

static void		dbg_print(union u_double value)
{
	printf("\e[4mvalue\e[0m\n");
	print_bits(value.l, 8 * sizeof(value.l));
	printf("\e[4msign\e[0m\n");
	print_bits(value.field.sign, F_SIZE_SIGN);
	printf("\e[4mexp\e[0m\n");
	print_bits(value.field.exponent, F_SIZE_EXPONENT);
	printf("\e[4msignificand\e[0m\n");
	print_bits(value.field.significand, F_SIZE_SIGNIFICAND);
}

static double		extract_arg(va_list ap)
{
	return (va_arg(ap, double));
}

static int		get_size(unsigned long n, char *base)
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
	double	a;
	int		i;
	int		j;
	int		digit;
	int		exp;

	a = value->field.sign ? -value->field.sign * value->n : value->n;
	exp = value->field.exponent - FLOAT_EXP_BIAS;
	i = 0;
	i += fill_start(str, specs);
	j = 0;
	while (a > 0.0 && j++ < 15)
	{
		digit = (int)a;
		printf("%c-", *(b + (char)digit));
		*(str + i++) = *(b + (char)digit);
		a -= digit;
		a *= 16;
	}
	*(str + i++) = 'p';
	*(str + i++) = exp < 0 ? '-' : '+';
	j = get_size_exp(exp);
	while (j--)
	{
		*(str + i + j) = '0' + (exp < 0 ? -(exp % 10) : exp % 10);
		exp /= 10;
	}
}

int				extract_float_conv_hex(va_list ap, t_specs *specs, char *b, char *str)
{
	union u_double	value;

	value.n = extract_arg(ap);
	dbg_print(value);
	specs->is_neg = value.field.sign;
	specs->flags |= PREFIX;
	specs->type |= specs->type & FLOAT_HEX ? HEXA : HEXA_C;
	specs->width_arg = specs->is_neg;
	specs->width_arg += get_size(value.field.significand, b);
	specs->width_arg += 2 + get_size_exp(value.field.exponent - FLOAT_EXP_BIAS);
	filter_specs(specs);
	print_specs(specs);
	printf("sign\texp\n%d\t%d\n", value.field.sign, value.field.exponent - FLOAT_EXP_BIAS);
	if (str)
		fill_str(&value, b, str, specs);
	return (1);
}
