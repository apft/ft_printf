/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_is_overflow.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:03:00 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 12:13:32 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_is_overflow(void)
{
	t_bigint	a;
	int			err;

	bigint_init_null(&a);
	a.blocks[BIGINT_N_BLOCKS] = BIGINT_OVERFLOW;
	err = !bigint_is_overflow(&a);
	if (err)
		print_bigint(&a);
	return (err);
}
