/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:58:40 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 17:00:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "filler.h"

int		float_fill_pref_radix(union u_double *value, char *str, t_specs *specs)
{
	int		i;

	i = filler(str, specs, FILL_START);
	*(str + i++) = value->field.exp ? '1' : '0';
	if (specs->precision || (specs->flags & FLOAT_FORCE_POINT))
		*(str + i++) = '.';
	return (i);
}

int		float_fill_exp(union u_double *value, char *str, t_specs *specs)
{
	int		exp;
	int		i;
	int		j;
	int		k;

	exp = value->field.exp;
	i = 0;
	if (specs->type & (FLOAT_HEXA | FLOAT_HEXA_C))
		*(str + i++) = (specs->type & FLOAT_HEXA) ? 'p' : 'P';
	*(str + i++) = (exp && (exp - FLOAT_EXP_BIAS) < 0) ? '-' : '+';
	if (!exp || !(exp -= FLOAT_EXP_BIAS))
		*(str + i) = '0';
	j = specs->width_suffix - 2;
	k = j;
	while (j--)
	{
		*(str + i + j) = '0' + (exp < 0 ? -(exp % 10) : exp % 10);
		exp /= 10;
	}
	return (i + k);
}

int		float_fill_floor_part(char *str, int pow_ten, int is_round_ten,
									t_frac frac)
{
	int		i;
	int		digit;

	i = 0;
	if (pow_ten < 0 && !is_round_ten)
	{
		*(str + i++) = '0';
		return (i);
	}
	while (i <= pow_ten)
	{
		digit = get_quotient_and_substract(frac.numerator, frac.denominator);
		*(str + i++) = '0' + (char)digit;
		bigint_mult_int(frac.numerator, frac.numerator, 10);
	}
	return (i);
}

int		float_fill_decimal_part(char *str, int pow_ten, int precision,
									t_frac frac)
{
	int		i;
	int		digit;

	i = 0;
	if (pow_ten < 0)
		while (i < precision && ++pow_ten)
			*(str + i++) = '0';
	while (i < precision && !bigint_is_null(frac.numerator))
	{
		digit = get_quotient_and_substract(frac.numerator, frac.denominator);
		*(str + i++) = '0' + (char)digit;
		bigint_mult_int(frac.numerator, frac.numerator, 10);
	}
	return (i);
}

void	float_fill_after(char *str, int start, int decimal_length,
									t_specs *specs)
{
	int		i;

	i = start;
	while (i - decimal_length < specs->precision)
		*(str + i++) = '0';
	while (i < specs->width)
		*(str + i++) = ' ';
}
