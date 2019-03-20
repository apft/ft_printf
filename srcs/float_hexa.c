/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:43:34 by apion             #+#    #+#             */
/*   Updated: 2019/03/20 20:32:35 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "float_pf.h"

unsigned int	float_hexa_extract_byte(unsigned long n, int byte_index)
{
	return ((unsigned int)(((n << (4 * byte_index)) & FLOAT_MASK_LEFT) >> 60));
}

static int		round_floor_part_if_needed(unsigned long n, int base_length,
								char *str)
{
	int		round_to_even;

	round_to_even = ((int)(n >> 60) == base_length / 2) && (*str - '0') % 2;
	if (((int)(n >> 60) > base_length / 2) || round_to_even)
	{
		if (*(str - 1) == '.')
			*(str - 2) += 1;
		else
			*(str - 1) += 1;
		return (1);
	}
	return (0);
}

int				float_hexa_round(unsigned long n, char *base, char *str,
								int precision)
{
	int		b;
	int		id;
	int		next;
	int		next_next;
	int		propagate;

	b = pf_strlen(base);
	if (!precision && round_floor_part_if_needed(n, b, str))
		return (1);
	propagate = 1;
	while (propagate && precision--)
	{
		id = float_hexa_extract_byte(n, precision);
		next = float_hexa_extract_byte(n, precision + 1);
		next_next = float_hexa_extract_byte(n, precision + 2);
		if (next > (b / 2))
			id += 1;
		if (next == (b / 2) && next_next)
			id += 1;
		propagate = (id == b) ? 1 : 0;
		*(str--) = *(base + (id == b ? 0 : id));
		if (propagate && *str == '.')
			(*(str - 1))++;
	}
	return (1);
}
