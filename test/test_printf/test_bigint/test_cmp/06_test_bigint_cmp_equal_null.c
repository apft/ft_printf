/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_bigint_cmp_equal_null.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:55:08 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 12:05:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_cmp_equal_null(void)
{
	t_bigint	a;
	t_bigint	b;
	int			diff;
	int			err;

	bigint_init_null(&a);
	bigint_init_null(&b);
	
	diff = bigint_cmp(&a, &b);
	err = !(diff == 0);
	if (err)
		print_diff_bigint(&a, &b, 0, 0, diff);	
	return (err);
}
