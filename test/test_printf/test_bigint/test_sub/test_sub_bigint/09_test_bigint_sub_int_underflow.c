/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_bigint_sub_int_underflow.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:18:13 by apion             #+#    #+#             */
/*   Updated: 2019/02/17 13:50:28 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_int_underflow(void)
{
	t_bigint		a;
	unsigned int	n;
	t_bigint		result;
	int				err;

	n = 0xffcb10d;
	a = (t_bigint){1, {0xff, 0, 0, 0, 0}};
	bigint_init_null(&result);

	bigint_sub_int(&result, &a, n);
	err = !bigint_is_underflow(&result);
	if (err)
		print_bigint(&result);
	return (err);
}
