/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_bigint_cmp_equal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:43:11 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 16:06:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_cmp_equal(void)
{
	t_bigint	a;
	t_bigint	b;
	int			diff;
	int			err;

	a = (t_bigint){2, {42, 42, 0, 0, 0}};
	b = (t_bigint){2, {42, 42, 0, 0, 0}};
	
	diff = bigint_cmp(&a, &b);
	err = !(diff == 0);
	if (err)
		print_diff_bigint(&a, &b, 0, 0, diff);	
	return (err);
}
