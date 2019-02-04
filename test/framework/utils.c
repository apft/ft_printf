/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <gguichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:44:52 by gguichar          #+#    #+#             */
/*   Updated: 2018/12/02 17:01:44 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	lu_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void			lu_putchar(char c)
{
	write(1, &c, 1);
}

void			lu_putstr(const char *str)
{
	write(1, str, lu_strlen(str));
}

void			lu_putnbr(int nb)
{
	long	n;

	n = nb;
	if (nb < 0)
	{
		n = -nb;
		lu_putchar('-');
	}
	if (n >= 10)
		lu_putnbr(n / 10);
	lu_putchar((n % 10) + '0');
}
