/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_is_overflow_false.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:05:38 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 12:13:55 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_is_overflow_false(void)
{
	t_bigint	a;
	int			err;

	bigint_init_null(&a);
	a.blocks[BIGINT_N_BLOCKS] = 32;
	a.blocks[0] = 57;
	err = bigint_is_overflow(&a);
	if (err)
		print_bigint(&a);
	return (err);
}
