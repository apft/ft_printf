/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_conv_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 20:35:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "float_hexa.h"
#include "filter.h"
#include "filler.h"
#include "extractor.h"

static int		get_size(unsigned long n)
{
	int		size;

	size = 1;
	n <<= 12;
	while (n <<= 4)
		++size;
	return (size);
}

static int		get_length_exp(unsigned int exp_biased)
{
	int		length;
	int		exp;

	if (!exp_biased)
		return (1);
	exp = exp_biased - FLOAT_EXP_BIAS;
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

	i = float_fill_pref_radix(value, str, specs);
	n = value->field.frac << 12;
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

	base = get_base(specs->type);
	specs->is_neg = value->field.sign;
	if (specs->flags & PREFIX)
		specs->flags |= FLOAT_FORCE_POINT;
	specs->flags |= PREFIX;
	if (!(specs->flags & PRECISION))
		specs->precision = value->field.frac ? get_size(value->field.frac) : 0;
	specs->width_suffix = 2 + get_length_exp(value->field.exp);
	filter_specs(specs);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
