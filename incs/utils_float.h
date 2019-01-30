/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/01/30 15:17:17 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_FLOAT_H
# define UTILS_FLOAT_H

# define F_SIZE_SIGN 1
# define F_SIZE_EXP 11
# define F_SIZE_FRAC 52

# define FLOAT_EXP_BIAS 1023
# define FLOAT_LONG_EXP_BIAS 1023

union					u_double
{
	double				n;
	unsigned long		l;
	struct
	{
		unsigned long	frac:F_SIZE_FRAC;
		unsigned int	exp:F_SIZE_EXP;
		unsigned int	sign:F_SIZE_SIGN;
	}					field;
};

void					print_bits(long n, unsigned int size);
void					dbg_print(union u_double value);

#endif
