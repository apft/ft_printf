/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:24:24 by apion             #+#    #+#             */
/*   Updated: 2019/01/19 10:24:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pf_min(int a, int b)
{
	return (a < b ? a : b);
}

int		pf_max(int a, int b)
{
	return (a < b ? b : a);
}
