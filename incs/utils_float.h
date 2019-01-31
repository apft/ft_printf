/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/01/31 18:23:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_FLOAT_H
# define UTILS_FLOAT_H

# define FLOAT_SIZE_SIGN 1
# define FLOAT_SIZE_EXP 11
# define FLOAT_SIZE_FRAC 52

# define FLOAT_EXP_BIAS 1023
# define FLOAT_EXP_MAX 2047
# define FLOAT_LONG_EXP_BIAS 1023
# define FLOAT_LONG_EXP_MAX 2047

# define FLOAT_MASK_RIGHT 0b1111UL
# define FLOAT_MASK_LEFT (0b1111UL << 60)

# include "utils.h"

union					u_double
{
	double				n;
	unsigned long		l;
	struct
	{
		unsigned long	frac:FLOAT_SIZE_FRAC;
		unsigned int	exp:FLOAT_SIZE_EXP;
		unsigned int	sign:FLOAT_SIZE_SIGN;
	}					field;
};

void					pf_round(unsigned long n, char *base, char *str,
								t_specs *specs);
void					print_bits(long n, unsigned int size);
void					dbg_print(union u_double *value);

#endif
