/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:24:36 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 12:38:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bigint_cmp(t_bigint *a, t_bigint *b)
{
	unsigned int	block;
	int				diff;

	if (a->length < b->length)
		return (-1);
	if (a->length > b->length)
		return (1);
	block = 0;
	while (block < a->length)
	{
		diff = a->blocks[block] - b->blocks[block];
		if (diff)
			return (diff);
		++block;
	}
	return (0);
}
