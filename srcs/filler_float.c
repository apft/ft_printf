/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:58:40 by apion             #+#    #+#             */
/*   Updated: 2019/01/31 18:24:18 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils_float.h"
#include "filler.h"

int		fill_float_pref_radix(union u_double *value, char *str, t_specs *specs)
{
	int		i;
	
	i = filler(str, specs, FILL_START);
	*(str + i++) = value->field.exp ? '1' : '0';
	if (specs->precision)
		*(str + i++) = '.';
	return (i);
}

void	fill_float_exp(union u_double *value, char *str, t_specs *specs)
{
	int		exp;
	int		i;
	int		j;

	exp = value->field.exp;
	i = 0;
	if (specs->type & (FLOAT_HEXA | FLOAT_HEXA_C))
		*(str + i++) = (specs->type & FLOAT_HEXA ) ? 'p' : 'P';
	*(str + i++) = (exp && (exp - FLOAT_EXP_BIAS) < 0) ? '-' : '+';
	if (!exp || !(exp -= FLOAT_EXP_BIAS))
		*(str + i) = '0';
	j = specs->width_suffix - 2;
	while ((exp /= (!(--j) ? 1 : 10)))
		*(str + i++) = '0' + (exp < 0 ? -(exp % 10) : exp % 10);
}

void	fill_float(union u_double *value, char *base, char *str, t_specs *specs)
{
}
