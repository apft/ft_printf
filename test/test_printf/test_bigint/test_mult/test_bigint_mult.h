/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_mult.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:11:23 by apion             #+#    #+#             */
/*   Updated: 2019/03/05 21:59:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_MULT_H
# define TEST_BIGINT_MULT_H

int		test_bigint_mult_int(t_bigint *a, unsigned int n, t_bigint *expected);
int		test_bigint_mult_int(t_bigint *a, unsigned int n, t_bigint *expected);
int		test_bigint_mult_int_one_easy(void);
int		test_bigint_mult_int_one_medium(void);
int		test_bigint_mult_int_one_medium2(void);
int		test_bigint_mult_int_small_easy(void);
int		test_bigint_mult_int_small_medium(void);
int		test_bigint_mult_int_small_carry(void);
int		test_bigint_mult_int_small_overflow(void);
int		test_bigint_mult_int_medium_easy(void);
int		test_bigint_mult_int_medium_medium(void);
int		test_bigint_mult_int_medium_carry(void);
int		test_bigint_mult_int_medium_overflow(void);

#endif
