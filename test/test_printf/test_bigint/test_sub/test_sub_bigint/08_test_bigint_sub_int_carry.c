/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_bigint_sub_int_carry.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:16:53 by apion             #+#    #+#             */
/*   Updated: 2019/03/01 19:30:15 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_int_carry(void)
{
	t_bigint	a;
	int			n;
	t_bigint	result;
	t_bigint	round_trip;
	int			diff;	

	a = (t_bigint){2, {256, 39840, 0, 0, 0}};
	n = 0xffffffff - 250;
	bigint_init_null(&result);
	bigint_init_null(&round_trip);

	bigint_sub_int(&result, &a, n);
	bigint_add_int(&round_trip, &result, n);
	diff = bigint_cmp(&a, &round_trip);
	if (diff)
		print_diff_bigint(&a, 0, &result, &round_trip, diff);	
	return (diff);
}
