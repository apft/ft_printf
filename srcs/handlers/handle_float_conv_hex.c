/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_conv_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/03/22 20:25:23 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "float_hexa.h"
#include "filter.h"
#include "filler.h"
#include "extractor.h"

static int		get_size(unsigned long n, int is_mod_ld)
{
	int		size;

	size = 1;
	n <<= (is_mod_ld) ? 3 : 12;
	while (n <<= 4)
		++size;
	return (size);
}

static int		get_length_exp(unsigned int exp_unbiased, int is_mod_ld)
{
	int		length;
	int		exp;

	if (!exp_unbiased)
		return (1);
	exp = exp_unbiased - (is_mod_ld ? FLOAT_LD_EXP_BIAS : FLOAT_EXP_BIAS);
	length = 1;
	while (exp /= 10)
		++length;
	return (length);
}

static void		fill_str(union u_double *value, char *b, char *str,
							t_specs *specs)
{
	unsigned long	n;
	int				i;
	int				byte_index;

	i = float_fill_pref_radix(value, b, str, specs);
	n = (specs->flags & MOD_LD) ? value->field_ld.frac << 4
		: value->field.frac << 12;
	byte_index = 0;
	if (specs->flags & PRECISION)
	{
		if (!specs->precision)
			byte_index += float_hexa_round(n, b, str + i, specs->precision);
		while ((byte_index + 1) < specs->precision && n << (4 * byte_index))
			*(str + i++) = *(b + float_hexa_extract_byte(n, byte_index++));
		if (byte_index < specs->precision && n << (4 * byte_index))
			byte_index += float_hexa_round(n, b, str + i++, specs->precision);
	}
	else
		while (n << (4 * byte_index))
			*(str + i++) = *(b + float_hexa_extract_byte(n, byte_index++));
	while (byte_index++ < specs->precision)
		*(str + i++) = '0';
	i += float_fill_exp(value, str + i, specs);
	i = pf_max(i, specs->width_arg);
	filler(str + i, specs, i);
}

int				handle_float_conv_hex(union u_double *value, t_specs *specs,
									char *str)
{
	char			*base;
	int				is_mod_ld;
	unsigned long	frac;
	unsigned int	exp_unbiased;

	is_mod_ld = specs->flags & MOD_LD;
	frac = is_mod_ld ? value->field_ld.frac : value->field.frac;
	exp_unbiased = is_mod_ld ? value->field_ld.exp : value->field.exp;
	base = get_base(specs->type);
	specs->is_neg = is_mod_ld ? value->field_ld.sign : value->field.sign;
	if (specs->flags & PREFIX)
		specs->flags |= FLOAT_FORCE_POINT;
	specs->flags |= PREFIX;
	if (!(specs->flags & PRECISION))
		specs->precision = frac ? get_size(frac, is_mod_ld) : 0;
	specs->width_suffix = 2 + get_length_exp(exp_unbiased, is_mod_ld);
	filter_specs(specs);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
