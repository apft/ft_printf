/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_test_bigint_sub_int_null.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:14:32 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 11:41:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_int_null(void)
{
	t_bigint	a;
	t_bigint	a_cpy;
	int			n;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {256, 3245460, 0, 0, 0}};
	bigint_copy(&a_cpy, &a);
	n = 0;
	expected = (t_bigint){2, {256, 3245460, 0, 0, 0}};

	bigint_sub_int(&a, &a, n);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(&a_cpy, 0, &a, &expected, diff);	
	return (diff);
}
