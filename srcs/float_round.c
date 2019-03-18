/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:24:38 by apion             #+#    #+#             */
/*   Updated: 2019/03/18 16:24:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"

int		float_will_round_to_ten(union u_double *value, int pow_ten,
								int precision, int flag)
{
	t_bigint	numerator;
	t_bigint	denominator;
	int			i;
	int			digit;
	int			digit_after;

	generate_bigints_num_den(value, pow_ten, &numerator, &denominator, flag);
	digit = get_quotient_and_substract(&numerator, &denominator);
	if (pow_ten < 0)
		pow_ten *= -1;
	if (digit != 9)
		return (0);
	bigint_mult_int(&numerator, &numerator, 10);
	digit_after = get_quotient_and_substract(&numerator, &denominator);
	i = 0;
	while (digit_after == 9 && i < (pow_ten + precision) && !bigint_is_null(&numerator))
	{
		bigint_mult_int(&numerator, &numerator, 10);
		digit_after = get_quotient_and_substract(&numerator, &denominator);
		++i;
	}
	if (digit_after >= 5 && i == (pow_ten + precision))
		return (1);
	if (digit_after > 5 && bigint_is_null(&numerator))
		return (1);
	return (0);
}

static int	propagate_rounding(char *str, int limit, int is_integer_part, int *offset)
{
	int		propagate;
	int		i;

	propagate = 1;
	i = 0;
	while (i < limit && propagate)
	{
		if (*(str - i) == '9')
			*(str - i) = '0';
		else
		{
			*(str - i) += 1;
			propagate = 0;
		}
		++i;
	}
	if (is_integer_part && i == limit && propagate)
		*(str - i) = '0';
	*offset = i;
	return (propagate);
}

static void	apply_rounding(int pow_ten, int precision, char *str)
{
	int		i;
	int		propagate;

	i = 0;
	propagate = 1;
	if (precision)
		propagate = propagate_rounding(str - i, precision, 0, &i);
	if (propagate)
	{
		if (*(str - i) == '.')
			propagate_rounding(str - i - 1, pow_ten, 1, &i);
		else
			propagate_rounding(str - i, pow_ten, 1, &i);
	}
}

void	float_apply_rounding_if_needed(char *str, int pow_ten, int precision,
									t_bigint *numerator, t_bigint *denominator)
{
	int		digit_after;

	if (bigint_is_null(numerator))
		return ;
	digit_after = get_quotient_and_substract(numerator, denominator);
	if (digit_after > 5)
		apply_rounding(pow_ten, precision, str);
	else if (digit_after == 5)
	{
		bigint_mult_int(numerator, numerator, 10);
		digit_after = get_quotient_and_substract(numerator, denominator);
		while (digit_after == 0 && !bigint_is_null(numerator))
		{
			bigint_mult_int(numerator, numerator, 10);
			digit_after = get_quotient_and_substract(numerator, denominator);
		}
		if (digit_after)
			apply_rounding(pow_ten, precision, str);
		else
		{
			if (pf_isdigit(*str) && (*str % 2) == 1)
				apply_rounding(pow_ten, precision, str);
			else if (*str == '.' && (*(str - 1) % 2) == 1)
				apply_rounding(pow_ten, precision, str - 1);
		}
	}
}

void		float_round(unsigned long n, char *base, char *str, t_specs *specs)
{
	int		b;
	int		id;
	int		next;
	int		next_next;
	int		j;
	int		propagate;

	b = pf_strlen(base);
	j = specs->precision;
	if (!j && (((int)(n >> 60) > b / 2)
				|| ((int)(n >> 60) == b / 2 && (*str - '0') % 2)))
	{
		if (*(str - 1) == '.')
			(*(str - 2))++;
		else
			(*(str - 1))++;
		return ;
	}
	propagate = 1;
	while (propagate && j--)
	{
		propagate = 0;
		id = ((n << (4 * j)) & FLOAT_MASK_LEFT) >> 60;
		next = ((n << (4 * (j + 1))) & FLOAT_MASK_LEFT) >> 60;
		next_next = ((n << (4 * (j + 2))) & FLOAT_MASK_LEFT) >> 60;
		if (next > (b / 2))
			id += 1;
		if (next == (b / 2) && next_next)
			id += 1;
		if (id == b)
			propagate = 1;
		*(str--) = *(base + (id == b ? 0 : id));
		if (propagate && *str == '.')
			(*(str - 1))++;
	}
}
