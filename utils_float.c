/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:09 by apion             #+#    #+#             */
/*   Updated: 2019/01/28 15:30:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		print_bits(long n, unsigned int size)
{
	int		i;
	int		j;

	printf("%d: ", n);
	i = size;
	while (i--)
		printf("%hhu", (n >> i) & 1);
	printf("\n");
}
