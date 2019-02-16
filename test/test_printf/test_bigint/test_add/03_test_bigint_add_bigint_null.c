/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_bigint_add_bigint_null.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:38:42 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 12:10:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_bigint_null(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {256, 23945870, 0, 0, 0}};
	bigint_init_null(&b);
	bigint_init_null(&result);
	expected = (t_bigint){2, {256, 23945870, 0, 0, 0}};

	bigint_add(&result, &a, &b);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &b, &result, &expected, diff);	
	return (diff);
}
