/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:47:16 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 11:48:26 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bigint_is_overflow(t_bigint *a)
{
	return (a->blocks[BIGINT_N_BLOCKS] == BIGINT_OVERFLOW);
}

int		bigint_is_underflow(t_bigint *a)
{
	return (a->blocks[BIGINT_N_BLOCKS] == BIGINT_UNDERFLOW);
}
