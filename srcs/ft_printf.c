/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:09:29 by apion             #+#    #+#             */
/*   Updated: 2019/02/14 12:32:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "wrapper.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	unsigned int	n;
	char			*str;

	va_start(ap, format);
	n = parse_size(format, ap);
	va_end(ap);
	va_start(ap, format);
	str = extract_str(format, n, ap);
	va_end(ap);
	return (print_str(1, str, n));
}

int		ft_printf_fd(int fd, const char *restrict format, ...)
{
	va_list			ap;
	unsigned int	n;
	char			*str;

	va_start(ap, format);
	n = parse_size(format, ap);
	va_end(ap);
	va_start(ap, format);
	str = extract_str(format, n, ap);
	va_end(ap);
	return (print_str(fd, str, n));
}

int		ft_printf_str(char **str, const char *restrict format, ...)
{
	va_list			ap;
	unsigned int	n;

	va_start(ap, format);
	n = parse_size(format, ap);
	va_end(ap);
	va_start(ap, format);
	*str = extract_str(format, n, ap);
	va_end(ap);
	return (*str ? n : -1);
}
