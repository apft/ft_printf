/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/01/28 17:48:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_FLOAT_H
# define UTILS_FLOAT_H

# define F_SIZE_SIGN 1
# define F_SIZE_EXPONENT 11
# define F_SIZE_SIGNIFICAND 52

# define FLOAT_EXP_BIAS 1023
# define FLOAT_LONG_EXP_BIAS 1023

union					u_double
{
	double				n;
	unsigned long		l;
	struct
	{
		unsigned long	significand:F_SIZE_SIGNIFICAND;
		unsigned int	exponent:F_SIZE_EXPONENT;
		unsigned int	sign:F_SIZE_SIGN;
	}					field;
};

void					print_bits(long n, unsigned int size);

#endif
