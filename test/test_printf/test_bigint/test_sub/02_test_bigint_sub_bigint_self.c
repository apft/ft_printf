/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_sub_bigint_self.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:35:20 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 13:01:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_bigint_self(void)
{
	t_bigint	a;
	t_bigint	result;
	t_bigint	expected;
	int			diff;	

	a = (t_bigint){3, {42, 589, 453, 0, 0}};
	bigint_init_null(&result);
	bigint_init_null(&expected);

	bigint_sub(&result, &a, &a);
	diff = bigint_cmp(&result, &expected);
	if (diff)
		print_diff_bigint(&a, &a, &result, &expected, diff);	
	return (diff);
}
