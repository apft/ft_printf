/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_bigint_add_bigint_null.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:38:42 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:18:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_self_bigint_null(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {256, 23945870, 0, 0, 0}};
	bigint_init_null(&b);
	expected = (t_bigint){2, {256, 23945870, 0, 0, 0}};

	bigint_add(&a, &a, &b);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(0, &b, &a, &expected, diff);	
	return (diff);
}
