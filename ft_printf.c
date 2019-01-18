/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:09:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/18 18:34:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "utils.h"

static ssize_t	print_str(const char *str, size_t size)
{
	ssize_t	ret;

	ret = write(1, str, size);
	free((void *)str);
	return (ret);
}

static int		parse_size(const char *f, va_list ap)
{
	t_specs		specs;
	int			n;

	n = 0;
	while (*f)
	{
		specs = (t_specs){0};
		if (*f== '%' && parse_specs(&f, &specs, ap, 0))
			n += specs.width;
		else
			++n;
		if (*f)
			++f;
	}
	return (n);
}

static char		*extract_str(const char *f, int n, va_list ap)
{
	char		*str;
	int			i;
	t_specs		specs;

	str = (char *)malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (0);
	i = 0;
	while (*f)
	{
		specs = (t_specs){0};
		if (*f== '%' && parse_specs(&f, &specs, ap, str + i))
			i += specs.width;
		else
			*(str + i++) = *f;
		if (*f)
			++f;
	}
	*(str + n) = 0;
	return (str);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			n;
	char		*str;

	va_start(ap, format);
	n = parse_size(format, ap);
	va_end(ap);
	va_start(ap, format);
	str = extract_str(format, n, ap);
	va_end(ap);
	return (print_str(str, n));
}
