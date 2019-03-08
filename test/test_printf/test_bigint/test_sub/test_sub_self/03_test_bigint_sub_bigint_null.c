/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_bigint_sub_bigint_null.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:38:42 by apion             #+#    #+#             */
/*   Updated: 2019/03/08 11:40:37 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_bigint_null(void)
{
	t_bigint	a;
	t_bigint	a_cpy;
	t_bigint	b;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {256, 23945870, 0, 0, 0}};
	bigint_init_null(&b);
	bigint_copy(&a_cpy, &a);
	expected = (t_bigint){2, {256, 23945870, 0, 0, 0}};

	bigint_sub(&a, &a, &b);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(&a_cpy, &b, &a, &expected, diff);	
	return (diff);
}
