/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:05:22 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:21:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bigint.h"

int		test_bigint_launcher()
{
	int		n;

	n = 0;
	n += test_bigint_init_launcher();
	n += test_bigint_cmp_launcher();
	n += test_bigint_add_launcher();
	n += test_bigint_shift_launcher();
	return (n);
}
