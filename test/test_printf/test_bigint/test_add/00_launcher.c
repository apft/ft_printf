/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:33 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:24:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_bigint_add.h"

int		test_bigint_add_launcher(void)
{
	int		n;

	n = 0;
	n += test_bigint_add_bigint_launcher();
	n += test_bigint_add_self_launcher();
	return (n);
}
