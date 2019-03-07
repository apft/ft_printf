/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_bigint_sub_int_underflow.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:18:13 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:36:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_sub_self_int_underflow(void)
{
	t_bigint		a;
	unsigned int	n;
	int				err;

	n = 0xffcb10d;
	a = (t_bigint){1, {0xff, 0, 0, 0, 0}};

	bigint_sub_int(&a, &a, n);
	err = !bigint_is_underflow(&a);
	if (err)
		print_bigint(&a);
	return (err);
}
