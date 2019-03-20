/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_limit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:40:55 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 15:55:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"
#include "handlers.h"
#include "filter.h"

#define FLOAT_LIMIT_INF "inf"
#define FLOAT_LIMIT_NAN "nan"

static int	handle_nan(t_specs *specs, char *str)
{
	if ((specs->width_min + specs->precision) <= 2 * pf_strlen(FLOAT_LIMIT_NAN))
		clear_flags(specs, SPACE);
	clear_flags(specs, PLUS);
	return (handle_str_conv(FLOAT_LIMIT_NAN, specs, str));
}

static int	handle_dbl(union u_double *value, t_specs *specs, char *str)
{
	if (!value->field.frac)
	{
		specs->is_neg = value->field.sign;
		return (handle_str_conv(FLOAT_LIMIT_INF, specs, str));
	}
	return (handle_nan(specs, str));
}

static int	handle_long_dbl(union u_double *value, t_specs *specs, char *str)
{
	if (value->field_ld.int_part && !value->field_ld.frac)
	{
		specs->is_neg = value->field_ld.sign;
		return (handle_str_conv(FLOAT_LIMIT_INF, specs, str));
	}
	return (handle_nan(specs, str));
}

int			handle_float_limit(union u_double *value, t_specs *specs, char *str,
							int flag)
{
	specs->type |= STRING;
	specs->precision = 0;
	clear_flags(specs, PRECISION | PAD);
	if (flag & MOD_LD)
		return (handle_long_dbl(value, specs, str));
	return (handle_dbl(value, specs, str));
}
