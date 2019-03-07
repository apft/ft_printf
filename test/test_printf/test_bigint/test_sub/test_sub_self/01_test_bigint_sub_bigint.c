/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_sub_bigint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:11:12 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:39:22 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_bigint(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	round_trip;
	int			diff;	

	a = (t_bigint){2, {420, 789, 0, 0, 0}};
	b = (t_bigint){1, {256, 0, 0, 0, 0}};
	bigint_init_null(&round_trip);

	bigint_sub(&a, &a, &b);
	bigint_add(&round_trip, &b, &a);
	diff = bigint_cmp(&round_trip, &a);
	if (diff)
		print_diff_bigint(0, &b, &a, &round_trip, diff);	
	return (diff);
}
