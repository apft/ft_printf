/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:09:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/15 19:41:38 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "utils.h"
#include "dbg_utils.h"

static ssize_t	print_str(const char *str, size_t size)
{
	ssize_t	ret;

	ret = write(1, str, size);
	free(str);
	return (ret);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	unsigned	n;
	char		*str;
	t_specs		specs;

	str = 0;
	va_start(ap, format);
	while (*format)
	{
		specs = (t_specs){0};
		if (*format == '%' && parse_specs(&format, &specs, ap))
		{
			n += specs.size;
		}
		else
			++n;
		if (*format)
			++format;
	}
	str = (char *)malloc(sizeof(*str) * n);
	if (!str)
		return (-1);
	*(str + n) = 0;
	va_end(ap);
	dbg_print_nbr("n", n);
	return (print_str(str, n));
}
