/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_pf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/03/14 09:24:39 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_PF_H
# define FLOAT_PF_H

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
# include "bigint.h"

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
int						get_quotient_and_substract(
								t_bigint *numerator, t_bigint *denominator);
void					generate_bigints_num_den(
								t_bigint *numerator, t_bigint *denominator,
								union u_double *value, int pow_ten);
void					float_apply_rounding_if_needed(char *str,
									int pow_ten, int precision,
									t_bigint *numerator, t_bigint *denominator);

#endif
