/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_mult_bigint.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:38:33 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 17:38:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_MULT_BIGINT_H
# define TEST_BIGINT_MULT_BIGINT_H

# define TEST_OVERFLOW 1

int		test_bigint_mult_int(t_bigint *a, unsigned int n, t_bigint *expected, int overflow);
int		test_bigint_mult_by_basis(t_bigint *a, t_bigint *b, t_bigint *expected, int overflow);
int		test_bigint_mult(t_bigint *a, t_bigint *b, t_bigint *expected, int overflow);

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
int		test_bigint_mult_by_basis_1(void);
int		test_bigint_mult_by_basis_2(void);
int		test_bigint_mult_by_basis_3(void);
int		test_bigint_mult_by_basis_4(void);
int		test_bigint_mult_by_basis_overflow(void);
int		test_bigint_mult_by_basis_overflow(void);
int		test_bigint_mult_easy(void);
int		test_bigint_mult_medium(void);
int		test_bigint_mult_carry(void);
int		test_bigint_mult_overflow(void);

#endif
