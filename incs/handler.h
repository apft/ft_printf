/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:02:05 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 22:10:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

int				print_str(int fd, const char *str, unsigned int size);
unsigned int	parse_size(const char *f, va_list ap);
char			*extract_str(const char *f, unsigned int n, va_list ap);

#endif
