/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_sub_bigint_carry.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:40:58 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:38:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_bigint_carry(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	round_trip;
	int			diff;	

	a = (t_bigint){3, {42, 789, 468, 0, 0}};
	b = (t_bigint){2, {257, BIGINT_BLOCK_MAX_VALUE, 0, 0, 0}};
	bigint_init_null(&round_trip);

	bigint_sub(&a, &a, &b);
	bigint_add(&round_trip, &b, &a);
	diff = bigint_cmp(&a, &round_trip);
	if (diff)
		print_diff_bigint(0, &b, &a, &round_trip, diff);	
	return (diff);
}
