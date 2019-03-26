/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:54:45 by apion             #+#    #+#             */
/*   Updated: 2019/03/26 12:08:52 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_TYPE_H
# define IS_TYPE_H

int		is_numeric_conversion(unsigned int type);
int		is_signed_conversion(unsigned int type);
int		is_hexa_conversion(unsigned int type);
int		is_float_conversion(unsigned int type);
int		is_type(t_specs *specs, unsigned int type);

#endif
