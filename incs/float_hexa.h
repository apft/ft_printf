/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_hexa.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:47:49 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 20:32:23 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HEXA_H
# define FLOAT_HEXA_H

unsigned int	float_hexa_extract_byte(unsigned long n, int byte_index);
int				float_hexa_round(unsigned long n, char *base, char *str,
								int precision);

#endif
