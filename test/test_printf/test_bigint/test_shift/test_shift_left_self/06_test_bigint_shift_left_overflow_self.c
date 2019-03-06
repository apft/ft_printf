/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_bigint_shift_left_self_overflow.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:16:04 by apion             #+#    #+#             */
/*   Updated: 2019/03/06 19:13:04 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_shift_left_self_overflow(void)
{
	unsigned int	n;
	t_bigint		a;
	t_bigint		b;
	t_bigint		expected;
	int				diff;	

	a = (t_bigint){3, {256, 3245460, 89458, 0, 0}};
	b = (t_bigint){3, {256, 3245460, 89458, 0, 0}};
	n = 32 + 32 + 7;
	expected = (t_bigint){3, {256, 3245460, 89458, 0, BIGINT_OVERFLOW}};

	bigint_shift_left_self(&a, n);
	diff = !bigint_is_overflow(&a);
	if (diff)
		print_diff_bigint(&b, 0, &a, &expected, diff);	
	return (diff);
}
