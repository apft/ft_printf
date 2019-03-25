/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_conv_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/03/25 12:00:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "float_hexa.h"
#include "filter.h"
#include "filler.h"
#include "extractor.h"

static int		get_size(unsigned long n, int is_long_dbl)
{
	int		size;

	size = 1;
	n <<= (is_long_dbl) ? 4 : 12;
	while (n <<= 4)
		++size;
	return (size);
}

static int		get_length_exp(t_field *fields)
{
	int		length;
	int		exp;

	exp = fields->exp;
	length = 1;
	while (exp /= 10)
		++length;
	return (length);
}

static void		fill_str(t_field *fields, char *b, char *str, t_specs *specs)
{
	unsigned long	n;
	int				i;
	int				byte_index;

	i = float_fill_pref_radix(fields, b, str, specs);
	n = (specs->flags & MOD_LD) ? fields->frac << 4 : fields->frac << 12;
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
	i += float_fill_exp(fields, str + i, specs);
	i = pf_max(i, specs->width_arg);
	filler(str + i, specs, i);
}

//TODO: subnormal numbers
int				handle_float_conv_hex(union u_double *value, t_specs *specs,
		char *str)
{
	char		*base;
	int			is_long_dbl;
	t_field		fields;

	base = get_base(specs->type);
	is_long_dbl = specs->flags & MOD_LD;
	float_extract_fields(&fields, value, is_long_dbl);
	specs->is_neg = fields.sign;
	if (specs->flags & PREFIX)
		specs->flags |= FLOAT_FORCE_POINT;
	specs->flags |= PREFIX;
	if (!(specs->flags & PRECISION))
		specs->precision = fields.frac ? get_size(fields.frac, is_long_dbl) : 0;
	specs->width_suffix = 2 + get_length_exp(&fields);
	filter_specs(specs);
	if (str)
		fill_str(&fields, base, str, specs);
	return (1);
}
