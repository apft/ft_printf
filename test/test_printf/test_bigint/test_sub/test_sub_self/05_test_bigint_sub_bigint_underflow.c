/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_sub_bigint_underflow.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:43:31 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 11:41:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_bigint_underflow(void)
{
	t_bigint	a;
	t_bigint	a_cpy;
	t_bigint	b;
	t_bigint	expected;
	int			err;	

	a = (t_bigint){4, {42, 789, 0, 2, 0}};
	b = (t_bigint){4, {256, 0, 0, BIGINT_BLOCK_MAX_VALUE, 0}};
	bigint_copy(&a_cpy, &a);
	expected = (t_bigint){0, {0, 0, 0, 0, BIGINT_UNDERFLOW}};

	bigint_sub(&a, &a, &b);
	err = !bigint_is_underflow(&a);
	if (err)
		print_diff_bigint(&a_cpy, &b, &a, &expected, err);
	return (err);
}
