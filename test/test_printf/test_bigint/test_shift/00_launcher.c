/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:52:37 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 13:57:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bigint_shift.h"

int		test_bigint_shift_launcher(void)
{
	int		n;

	n = 0;
	n += test_bigint_shift_left_launcher();
	return (n);
}
