/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_conv_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:00:29 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 16:59:23 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils_float.h"
#include "float_round.h"
#include "filter.h"
#include "filler.h"
#include "filler_float.h"
#include "extractor.h"

#include <stdio.h>
static int		get_size(unsigned long n)
{
	int		size;

	size = 1;
	n <<= 12;
	while (n <<= 4)
		++size;
//	printf("arg_size= %d\n", size);
	return (size);
}

static int		get_size_exp(int exp)
{
	int		size;

	size = 1;
	while (exp /= 10)
		++size;
//	printf("exp_size= %d\n", size);
	return (size);
}

static void		fill_str(union u_double *value, char *b, char *str,
							t_specs *specs)
{
	unsigned long	n;
	int				i;
	int				j;

	i = fill_float_pref_radix(value, str, specs);
	n = value->field.frac << 12;
	j = 0;
	if (specs->flags & PRECISION)
	{
		if (!specs->precision)
		{
			float_round(n, b, str + i, specs);
			++j;
		}
		while ((j + 1) < specs->precision && n << (4 * j))
			*(str + i++) = *(b + (((n << (4 * j++)) & FLOAT_MASK_LEFT) >> 60));
		if (j < specs->precision && n << (4 * j))
		{
			float_round(n, b, str + i++, specs);
			++j;
		}
	}
	else
		while (n << (4 * j))
			*(str + i++) = *(b + (((n << (4 * j++)) & FLOAT_MASK_LEFT) >> 60));
	while (j++ < specs->precision)
		*(str + i++) = '0';
	i += fill_float_exp(value, str + i, specs);
	filler(str + pf_max(i, specs->width_arg), specs, pf_max(i, specs->width_arg));
}

int				handle_float_conv_hex(union u_double *value, t_specs *specs,
									char *str)
{
	char			*base;

	base = get_base(specs->type);
//	if (str)
//		dbg_print(value);
	specs->is_neg = value->field.sign;
	specs->flags |= PREFIX;
	if (!(specs->flags & PRECISION))
		specs->precision = value->field.frac ? get_size(value->field.frac) : 0;
	specs->width_suffix = 2 + (value->field.exp ? get_size_exp(value->field.exp - FLOAT_EXP_BIAS_DBL) : 1);
	filter_specs(specs);
//	if (str)
//		print_specs(specs);
//	printf("sign\texp\n%d\t%d\n", value->field.sign, value->field.exp - FLOAT_EXP_BIAS);
	if (str)
		fill_str(value, base, str, specs);
	return (1);
}
