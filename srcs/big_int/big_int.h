/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:48:57 by apion             #+#    #+#             */
/*   Updated: 2019/02/14 13:57:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_INT_H
# define BIG_INT_H

# define BIGINT_N_BLOCKS 4
# define BIGINT_SIZE_BLOCK 32

typedef struct	s_bigint
{
	int		length;
	int		blocks[BIGINT_N_BLOCKS + 1];
}				t_bigint;

#endif
