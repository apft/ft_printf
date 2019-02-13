/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 00:05:04 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 14:18:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "utils.h"
# include "utils_float.h"

int		handle_int_conv(union u_value *value, t_specs *specs, char *str);
int		handle_int_conv_char(char value, t_specs *specs, char *str);
int		handle_int_conv_short(short value, t_specs *specs, char *str);
int		handle_int_conv_int(int value, t_specs *specs, char *str);
int		handle_int_conv_long(long value, t_specs *specs, char *str);
int		handle_int_conv_long_long(long long value, t_specs *s, char *str);

int		handle_int_conv_u(union u_value *value, t_specs *specs, char *str);
int		handle_int_conv_uchar(unsigned char value, t_specs *specs, char *str);
int		handle_int_conv_ushort(unsigned short value, t_specs *specs, char *str);
int		handle_int_conv_uint(unsigned int value, t_specs *specs, char *str);
int		handle_int_conv_ulong(unsigned long value, t_specs *specs, char *str);
int		handle_int_conv_ulong_long(unsigned long long v, t_specs *s, char *str);

int		handle_char_conv(unsigned char value, t_specs *s, char *str);

int		handle_str_conv(char *value, t_specs *specs, char *str);

int		handle_float_conv(union u_double *value, t_specs *specs, char *str);
int		handle_float_conv_hex(union u_double *value, t_specs *specs, char *str);

#endif
