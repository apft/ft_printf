/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:00:05 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:28:02 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "test_bigint_mult.h"

int		test_bigint_mult_launcher(void)
{
	int		n;

	n = 0;
	n += test_bigint_mult_bigint_launcher();
	n += test_bigint_mult_self_launcher();
}
