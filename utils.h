/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:25:47 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 23:52:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_specs
{
	int		flags;
	int		precision;
	int		type;
	int		is_neg;
	int		width_arg;
	int		width;
}				t_specs;

enum	flags
{
	LEFT = 1,
	PLUS = 2,
	SPACE = 4,
	PREFIX = 8,
	PAD = 16,
	CHAR = 32,
	SHORT = 64,
	LONG = 128,
	LONG_LONG = 256,
	SIZE_T = 512,
	WIDTH = 1024,
	PRECISION = 2048
};

enum	type
{
	INT = 1,
	OCTAL = 2,
	UINT = 4,
	HEXA = 8,
	HEXA_CAP = 16,
	FLOAT = 32,
	EXP = 64,
	EXP_CAP = 128,
	FLOAT_G = 256,
	FLOAT_G_CAP = 512,
	T_CHAR = 1024,
	STRING = 2048,
	POINTER = 4096,
	PERCENT = 8192
};

#endif
