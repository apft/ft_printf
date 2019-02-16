/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_bigint_add_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:11:27 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 12:28:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_int(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		result;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){1, {256, 0, 0, 0, 0}};
	n = 42;
	bigint_init_null(&result);
	expected = (t_bigint){1, {256 + n, 0, 0, 0, 0}};

	bigint_add_int(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
