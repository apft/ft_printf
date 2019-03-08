/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_test_bigint_add_int_null.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:14:32 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 17:15:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_int_null(void)
{
	t_bigint	a;
	int			n;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){2, {256, 3245460, 0, 0, 0}};
	n = 0;
	bigint_init_null(&result);
	expected = (t_bigint){2, {256, 3245460, 0, 0, 0}};

	bigint_add_int(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
