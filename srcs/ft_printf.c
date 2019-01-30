/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:09:29 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 21:56:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "utils.h"
#include "parser.h"

static int	print_str(int fd, const char *str, size_t size)
{
	int	ret;

	ret = write(fd, str, size);
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
		specs = (t_specs){0, 0, 0, 0, 0, 0, 0, 0};
		if (*f == '%' && parse_specs(&f, &specs, ap, 0))
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

	printf("\e[1mn= %d\e[0m\n", n);
	str = (char *)malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (0);
	i = 0;
	while (*f)
	{
		specs = (t_specs){0, 0, 0, 0, 0, 0, 0, 0};
		if (*f == '%' && parse_specs(&f, &specs, ap, str + i))
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
	return (print_str(1, str, n));
}

int				ft_printf_fd(int fd, const char *restrict format, ...)
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
	return (print_str(fd, str, n));
}

int				ft_printf_str(char **str, const char *restrict format, ...)
{
	va_list		ap;
	int			n;

	va_start(ap, format);
	n = parse_size(format, ap);
	va_end(ap);
	va_start(ap, format);
	*str = extract_str(format, n, ap);
	va_end(ap);
	return (*str ? n : -1);
}