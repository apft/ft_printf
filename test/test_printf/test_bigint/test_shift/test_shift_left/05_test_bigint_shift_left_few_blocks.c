/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_shift_left_few_blocks.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:14:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:34:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_shift_left_few_blocks(void)
{
	unsigned int	n;
	t_bigint		a;
	t_bigint		result;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){2, {256, 89458, 0, 0, 0}};
	n = 32 + 7;
	bigint_init_null(&result);
	expected = (t_bigint){3, {0, 128 * 256, 128 * 89458, 0, 0}};

	bigint_shift_left(&result, &a, n);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, 0, &result, &expected, diff);	
	return (diff);
}
