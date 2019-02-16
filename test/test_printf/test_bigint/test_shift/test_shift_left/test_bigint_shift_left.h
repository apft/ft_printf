/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_shift_left.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:02:25 by apion             #+#    #+#             */
/*   Updated: 2019/02/16 14:07:15 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_SHIFT_LEFT_H
# define TEST_BIGINT_SHIFT_LEFT_H

int		test_bigint_shift_left_null(void);
int		test_bigint_shift_left_one(void);
int		test_bigint_shift_left_pos(void);
int		test_bigint_shift_left_block(void);
int		test_bigint_shift_left_few_blocks(void);
int		test_bigint_shift_left_overflow(void);

#endif
