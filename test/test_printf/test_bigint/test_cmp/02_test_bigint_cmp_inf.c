/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_bigint_cmp_inf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:49:51 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 16:06:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_cmp_inf(void)
{
	t_bigint	a;
	t_bigint	b;
	int			diff;
	int			err;

	a = (t_bigint){3, {42, 42, 243, 0, 0}};
	b = (t_bigint){3, {42, 42, 5689851, 0, 0}};
	
	diff = bigint_cmp(&a, &b);
	err = !(diff < 0);
	if (err)
		print_diff_bigint(&a, &b, 0, 0, diff);	
	return (err);
}
