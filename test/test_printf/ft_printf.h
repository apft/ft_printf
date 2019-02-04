/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:55:48 by apion             #+#    #+#             */
/*   Updated: 2019/02/04 15:43:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *restrict f, ...);
int		ft_printf_fd(int fd, const char *restrict f, ...);
int		ft_printf_str(char **str, const char *restrict f, ...);

#endif
