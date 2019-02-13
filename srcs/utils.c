/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:24:24 by apion             #+#    #+#             */
/*   Updated: 2019/02/12 22:00:22 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		pf_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

int		pf_min(int a, int b)
{
	return (a < b ? a : b);
}

int		pf_max(int a, int b)
{
	return (a < b ? b : a);
}

char	*get_base(int type)
{
	if (type & OCTAL)
		return (BASE_OCT);
	if (type & (HEXA | FLOAT_HEXA))
		return (BASE_HEXA);
	if (type & (HEXA_C | FLOAT_HEXA_C))
		return (BASE_HEXA_C);
	return (BASE_DEC);
}
