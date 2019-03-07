/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_mult_self.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:35:10 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:39:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_MULT_SELF_H
# define TEST_BIGINT_MULT_SELF_H

# define TEST_OVERFLOW 1

int		test_bigint_mult_self_int(t_bigint *a, unsigned int n, t_bigint *expected, int overflow);
int		test_bigint_mult_self_by_basis(t_bigint *a, t_bigint *b, t_bigint *expected, int overflow);
int		test_bigint_mult_self(t_bigint *a, t_bigint *b, t_bigint *expected, int overflow);

int		test_bigint_mult_self_int_one_easy(void);
int		test_bigint_mult_self_int_one_medium(void);
int		test_bigint_mult_self_int_one_medium2(void);
int		test_bigint_mult_self_int_small_easy(void);
int		test_bigint_mult_self_int_small_medium(void);
int		test_bigint_mult_self_int_small_carry(void);
int		test_bigint_mult_self_int_small_overflow(void);
int		test_bigint_mult_self_int_medium_easy(void);
int		test_bigint_mult_self_int_medium_medium(void);
int		test_bigint_mult_self_int_medium_carry(void);
int		test_bigint_mult_self_int_medium_overflow(void);
int		test_bigint_mult_self_by_basis_1(void);
int		test_bigint_mult_self_by_basis_2(void);
int		test_bigint_mult_self_by_basis_3(void);
int		test_bigint_mult_self_by_basis_4(void);
int		test_bigint_mult_self_by_basis_overflow(void);
int		test_bigint_mult_self_by_basis_overflow(void);
int		test_bigint_mult_self_easy(void);
int		test_bigint_mult_self_medium(void);
int		test_bigint_mult_self_carry(void);
int		test_bigint_mult_self_overflow(void);

#endif
