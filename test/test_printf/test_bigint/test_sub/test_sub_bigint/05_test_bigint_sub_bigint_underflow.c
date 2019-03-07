/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_sub_bigint_underflow.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:43:31 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 13:28:16 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_bigint_underflow(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	result;
	int			err;	

	a = (t_bigint){4, {42, 789, 0, 2, 0}};
	b = (t_bigint){4, {256, 0, 0, BIGINT_BLOCK_MAX_VALUE, 0}};
	bigint_init_null(&result);

	bigint_sub(&result, &a, &b);
	err = !bigint_is_underflow(&result);
	if (err)
	{
		print_bigint(&a);
		print_bigint(&b);
		print_bigint(&result);
	}
	return (err);
}
