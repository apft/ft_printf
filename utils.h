/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:25:47 by apion             #+#    #+#             */
/*   Updated: 2019/01/18 14:28:37 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_specs
{
	int		flags;
	int		type;
	int		precision;
	int		width_min;
	int		width_arg;
	int		width_prefix;
	int		width;
	int		is_neg;
}				t_specs;

enum	flags
{
	LEFT = 1,
	PLUS = 1 << 1,
	SPACE = 1 << 2,
	PREFIX = 1 << 3,
	PAD = 1 << 4,
	WIDTH = 1 << 5,
	PRECISION = 1 << 6,
	MOD_HH = 1 << 7,
	MOD_H = 1 << 8,
	MOD_L = 1 << 9,
	MOD_LL = 1 << 10,
	MOD_LD = 1 << 11
};

enum	type
{
	INT = 1,
	OCTAL = 1 << 1,
	UINT = 1 << 2,
	HEXA = 1 << 3,
	HEXA_C = 1 << 4,
	FLOAT = 1 << 5,
	CHAR = 1 << 6,
	STRING = 1 << 7,
	POINTER = 1 << 8,
	PERCENT = 1 << 9
};

#endif
