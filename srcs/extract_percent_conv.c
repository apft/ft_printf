/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_percent_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:29:48 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 18:42:08 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "filter.h"
#include "filler.h"

static void		fill_str(unsigned char value, char *str, t_specs *specs)
{
	int		i;

	i = 0;
	i += filler(str, specs, FILL_START);
	*(str + i++) = value;
	filler(str + i, specs, i);
}

int				extract_percent_conv(va_list ap, t_specs *specs, char *str)
{
	unsigned char	value;

	(void)ap;
	value = '%';
	specs->width_arg = 1;
	filter_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}
