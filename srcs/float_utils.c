/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 16:57:55 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_pf.h"
#include "utils.h"

static int	float_compute_pow_ten_long_dbl(long double n)
{
	int		pow_ten;

	pow_ten = 0;
	if (!n)
		return (pow_ten);
	if (n < 0)
		n *= -1;
	if (n > 10.0)
	{
		while (n > 10.0)
		{
			n /= 10;
			++pow_ten;
		}
	}
	else if (n < 1.0)
	{
		while (n < 1.0)
		{
			n *= 10;
			--pow_ten;
		}
	}
	return (pow_ten);
}

static int	float_compute_pow_ten_dbl(double n)
{
	return (float_compute_pow_ten_long_dbl((long double)n));
}

int			float_compute_pow_ten(union u_double *value, int flag)
{
	if (flag & MOD_LD)
		return (float_compute_pow_ten_long_dbl(value->type_long_dbl));
	return (float_compute_pow_ten_dbl(value->type_dbl));
}
