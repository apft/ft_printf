/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_bigint_shift_left_self_block.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:13:51 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 11:28:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_shift_left_self_block(void)
{
	unsigned int	n;
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){3, {256, 3245460, 89458, 0, 0}};
	b = (t_bigint){3, {256, 3245460, 89458, 0, 0}};
	n = 32;
	expected = (t_bigint){4, {0, 256, 3245460, 89458, 0}};

	bigint_shift_left_self(&a, n);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(&b, 0, &a, &expected, diff);	
	return (diff);
}
