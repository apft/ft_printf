/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/03/12 11:38:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_FLOAT_H
# define UTILS_FLOAT_H

# define FLOAT_DEFAULT_PRECISION 6

# define FLOAT_SIZE_SIGN 1
# define FLOAT_SIZE_EXP 11
# define FLOAT_SIZE_FRAC 52

# define FLOAT_EXP_BIAS_DBL 1023
# define FLOAT_EXP_MAX_DBL 2047
# define FLOAT_EXP_BIAS_LONG_DBL 1023
# define FLOAT_EXP_MAX_LONG_DBL 2047

# define FLOAT_MASK_RIGHT 0b1111UL
# define FLOAT_MASK_LEFT (0b1111UL << 60)

# include "utils.h"

union					u_double
{
	double				type_dbl;
	unsigned long		type_long;
	struct
	{
		unsigned long	frac:FLOAT_SIZE_FRAC;
		unsigned int	exp:FLOAT_SIZE_EXP;
		unsigned int	sign:FLOAT_SIZE_SIGN;
	}					field;
};

int						pf_compute_float_pow_ten(double n);
void					pf_round(unsigned long n, char *base, char *str,
								t_specs *specs);
void					print_bits(long n, unsigned int size);
void					dbg_print(union u_double *value);

#endif
