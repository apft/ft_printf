/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_bigint_sub_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:11:27 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 11:41:42 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_int(void)
{
	t_bigint		a;
	t_bigint	a_cpy;
	unsigned int	n;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){1, {256, 0, 0, 0, 0}};
	bigint_copy(&a_cpy, &a);
	n = 42;
	expected = (t_bigint){1, {256 - n, 0, 0, 0, 0}};

	bigint_sub_int(&a, &a, n);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(&a_cpy, &a, &a, &expected, diff);
	return (diff);
}
