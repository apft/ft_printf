/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_bigint_cmp_length_sup.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:53:01 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 16:07:26 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bigint.h"

int		test_bigint_cmp_length_sup(void)
{
	t_bigint	a;
	t_bigint	b;
	int			diff;
	int			err;

	a = (t_bigint){4, {42, 42, 243, 32450, 0}};
	b = (t_bigint){2, {42, 42, 0, 0, 0}};
	
	diff = bigint_cmp(&a, &b);
	err = !(diff > 0);
	if (err)
		print_diff_bigint(&a, &b, 0, 0, diff);	
	return (err);
}
