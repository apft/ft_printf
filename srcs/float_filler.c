/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:58:40 by apion             #+#    #+#             */
/*   Updated: 2019/03/22 22:23:39 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "filler.h"

int		float_fill_pref_radix(union u_double *value, char *b, char *str,
							t_specs *specs)
{
	int				i;
	int				is_mod_ld;
	unsigned int	exp_unbiased;
	unsigned int	implicit_bit;
	unsigned int	integer_part;

	is_mod_ld = specs->flags & MOD_LD;
	exp_unbiased = is_mod_ld ? value->field_ld.exp : value->field.exp;
	implicit_bit = is_mod_ld ? value->field_ld.int_part : !!exp_unbiased;
	i = filler(str, specs, FILL_START);
	if (is_mod_ld)
	{
		integer_part =
			(unsigned int)(value->field_ld.frac >> 60) | (implicit_bit << 3);
		*(str + i++) = *(b + integer_part);
	}
	else
		*(str + i++) = '0' + implicit_bit;
	if (specs->precision || (specs->flags & FLOAT_FORCE_POINT))
		*(str + i++) = '.';
	return (i);
}

int		float_fill_exp(union u_double *value, char *str, t_specs *specs)
{
	unsigned int	exp_unbiased;
	int				exp;
	int				i;
	int				j;

	if (specs->flags & MOD_LD)
		exp_unbiased = value->field_ld.exp - (value->field_ld.frac || value->field_ld.exp ? 3 : 0);
	else
		exp_unbiased = value->field.exp;
	if (specs->flags & MOD_LD)
		exp = exp_unbiased - FLOAT_LD_EXP_BIAS;
	else
		exp = exp_unbiased - FLOAT_EXP_BIAS;
	i = 0;
	*(str + i++) = (specs->type & FLOAT_HEXA) ? 'p' : 'P';
	*(str + i++) = (exp_unbiased && exp < 0) ? '-' : '+';
	if (!exp_unbiased || !exp)
		*(str + i) = '0';
	j = specs->width_suffix - 2;
	while (exp_unbiased && exp && j--)
	{
		*(str + i + j) = '0' + (exp < 0 ? -(exp % 10) : exp % 10);
		exp /= 10;
	}
	return (i + specs->width_suffix - 2);
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
	i += fill_char(str + i, '0', specs->precision + decimal_length - i);
	fill_char(str + i, ' ', specs->width - i);
}
