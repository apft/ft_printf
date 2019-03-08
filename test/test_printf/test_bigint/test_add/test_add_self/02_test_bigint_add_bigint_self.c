/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_add_bigint_self.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:35:20 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:18:14 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_add_self_bigint_self(void)
{
	t_bigint	a;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){3, {42, 589, 453, 0, 0}};
	expected = (t_bigint){3, {84, 1178, 906, 0, 0}};

	bigint_add(&a, &a, &a);
	diff = bigint_cmp(&a, &expected);
	if (diff)
		print_diff_bigint(0, &a, &a, &expected, diff);	
	return (diff);
}
