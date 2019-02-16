/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_shift_left_one.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:10:03 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:13:33 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_shift_left_one(void)
{
	unsigned int	n;
	t_bigint		a;
	t_bigint		result;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){3, {256, 3245460, 89458, 0, 0}};
	n = 1;
	bigint_init_null(&result);
	expected = (t_bigint){3, {2 * 256, 2 * 3245460, 2 * 89458, 0, 0}};

	bigint_shift_left(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
