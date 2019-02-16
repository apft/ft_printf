/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_shift_left_self_few_blocks.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:14:35 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 17:14:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_shift_left_self_few_blocks(void)
{
	unsigned int	n;
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){2, {256, 89458, 0, 0, 0}};
	b = (t_bigint){2, {256, 89458, 0, 0, 0}};
	n = 32 + 7; // 2^7 = 128
	expected = (t_bigint){3, {0, 128 * 256, 128 * 89458, 0, 0}};

	bigint_shift_left_self(&a, n);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(&b, 0, &a, &expected, diff);	
	return (diff);
}
