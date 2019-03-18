/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_pf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:01:06 by apion             #+#    #+#             */
/*   Updated: 2019/03/18 16:06:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_PF_H
# define FLOAT_PF_H

# define FLOAT_DEFAULT_PRECISION 6

# define FLOAT_SIZE_SIGN 1
# define FLOAT_SIZE_EXP 11
# define FLOAT_SIZE_FRAC 52

# define FLOAT_EXP_BIAS 1023
# define FLOAT_EXP_MAX 2047

# define FLOAT_LD_SIZE_SIGN 1
# define FLOAT_LD_SIZE_EXP 15
# define FLOAT_LD_INTEGER_PART 1
# define FLOAT_LD_SIZE_FRAC 63

# define FLOAT_LD_EXP_BIAS 16383
# define FLOAT_LD_EXP_MAX 32767

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
	long double				type_long_dbl;
	unsigned long long		type_ll;
	struct
	{
		unsigned long	frac:FLOAT_LD_SIZE_FRAC;
		unsigned int	int_part:FLOAT_LD_INTEGER_PART;
		unsigned int	exp:FLOAT_LD_SIZE_EXP;
		unsigned int	sign:FLOAT_LD_SIZE_SIGN;
	}						field_ld;
};

void					print_bits(long n, unsigned int size);
void					dbg_print(union u_double *value);

int						float_compute_pow_ten(double n);

int						get_quotient_and_substract(
								t_bigint *numerator, t_bigint *denominator);
void					generate_bigints_num_den(
								union u_double *value, int pow_ten,
								t_bigint *numerator, t_bigint *denominator);

int						float_fill_floor_part(char *str, int pow_ten, int is_round_ten, t_bigint *numerator,
									t_bigint *denominator);
int						float_fill_decimal_part(char *str, int pow_ten, int precision,
									t_bigint *numerator, t_bigint *denominator);
int						float_fill_pref_radix(union u_double *value,
								char *str, t_specs *specs);
int						float_fill_exp(union u_double *value,
								char *str, t_specs *specs);

int						float_will_round_to_ten(union u_double *value,
								int pow_ten, int precision);
void					float_apply_rounding_if_needed(char *str,
								int pow_ten, int precision,
								t_bigint *numerator, t_bigint *denominator);

#endif
