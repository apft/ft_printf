/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:59:45 by apion             #+#    #+#             */
/*   Updated: 2019/03/26 11:27:38 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *restrict format, ...);

int		main(void)
{
	ft_printf("%y%{b}%{u}bonjour%{\\u} ABC  %{reverse}%{yellow}%{toi}%{\\fg}%{b\0l\n");
}
