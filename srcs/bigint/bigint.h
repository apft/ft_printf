/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:48:57 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 11:12:18 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

# define BIGINT_N_BLOCKS 4
# define BIGINT_SIZE_BLOCK 32

# define BIGINT_OVERFLOW 0xf
# define BIGINT_UNDERFLOW 0xf0

typedef struct	s_bigint
{
	unsigned int	length;
	unsigned int	blocks[BIGINT_N_BLOCKS + 1];
}				t_bigint;

void			print_bigint(t_bigint *value);
void			bigint_add(t_bigint *r, t_bigint *a, t_bigint *b);
void			bigint_shift_left(t_bigint *r, t_bigint *a, unsigned int shift);
void			bigint_shift_left_self(t_bigint *a, unsigned int shift);

#endif