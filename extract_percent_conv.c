/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_percent_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:29:48 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 12:40:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"

static void		fill_str(unsigned char value, char *str, t_specs *specs)
{
	int		i;

	i = 0;
	i += fill_start(str, specs);
	*(str + i++) = value;
	fill_end(str + i, i, specs);
}

int				extract_percent_conv(t_specs *specs, char *str)
{
	unsigned char	value;

	value = '%';
	specs->width_arg = 1;
	filter_specs(specs);
	print_specs(specs);
	if (str)
		fill_str(value, str, specs);
	return (1);
}
