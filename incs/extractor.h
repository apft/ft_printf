/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:46:31 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 18:42:39 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACTOR_H
# define EXTRACTOR_H

# include <stdarg.h>
# include "utils.h"

int		extract_int_conv(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_char(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_short(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_int(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_long(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_long_long(va_list ap, t_specs *s, char *str);

int		extract_int_conv_u(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_uchar(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_ushort(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_uint(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_ulong(va_list ap, t_specs *specs, char *str);
int		extract_int_conv_ulong_long(va_list ap, t_specs *s, char *str);

int		handle_char_conv(unsigned char value, t_specs *s, char *str);
int		extract_char_conv(va_list ap, t_specs *specs, char *str);

int		handle_str_conv(char *value, t_specs *specs, char *str);
int		extract_str_conv(va_list ap, t_specs *specs, char *str);

int		extract_percent_conv(va_list ap, t_specs *specs, char *str);
int		extract_pointer_conv(va_list ap, t_specs *specs, char *str);

int		extract_float_conv(va_list ap, t_specs *specs, char *str);
int		extract_float_conv_hex(va_list ap, t_specs *specs, char *str);

#endif
