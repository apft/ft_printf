/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:48:57 by apion             #+#    #+#             */
/*   Updated: 2019/02/14 13:08:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_INT_H
# define BIG_INT_H

# define BIG_INT_BLOCKS_SIZE 4

typedef struct	s_bigint
{
	int		length;
	int		blocks[BIG_INT_BLOCKS_SIZE + 1];
}				t_bigint;

#endif
