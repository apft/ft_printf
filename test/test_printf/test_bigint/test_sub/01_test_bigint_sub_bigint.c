/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_sub_bigint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:11:12 by apion             #+#    #+#             */
/*   Updated: 2019/03/01 19:26:02 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_bigint(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	t_bigint	round_trip;
	int			diff;	

	a = (t_bigint){2, {420, 789, 0, 0, 0}};
	b = (t_bigint){1, {256, 0, 0, 0, 0}};
	bigint_init_null(&result);
	bigint_init_null(&round_trip);

	bigint_sub(&result, &a, &b);
	bigint_add(&round_trip, &b, &result);
	diff = bigint_cmp(&round_trip, &a);
	if (diff)
		print_diff_bigint(&a, &b, &result, &round_trip, diff);	
	return (diff);
}
