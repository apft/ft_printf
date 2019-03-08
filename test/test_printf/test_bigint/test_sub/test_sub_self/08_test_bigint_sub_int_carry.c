/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_bigint_sub_int_carry.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:16:53 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 12:05:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_int_carry(void)
{
	t_bigint	a;
	t_bigint	a_cpy;
	int			n;
	t_bigint	round_trip;
	int			diff;	

	a = (t_bigint){2, {256, 39840, 0, 0, 0}};
	bigint_copy(&a_cpy, &a);
	n = 0xffffffff - 250;
	bigint_init_null(&round_trip);

	bigint_sub_int(&a, &a, n);
	bigint_add_int(&round_trip, &a, n);
	diff = bigint_cmp(&a_cpy, &round_trip);
	if (diff)
		print_diff_bigint(&a_cpy, 0, &a_cpy, &round_trip, diff);	
	return (diff);
}
