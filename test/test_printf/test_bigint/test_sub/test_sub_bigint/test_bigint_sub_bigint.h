/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_sub_bigint.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:24 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:30:52 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_SUB_BIGINT_H
# define TEST_BIGINT_SUB_BIGINT_H

int		test_bigint_sub_bigint(void);
int		test_bigint_sub_bigint_self(void);
int		test_bigint_sub_bigint_null(void);
int		test_bigint_sub_bigint_carry(void);
int		test_bigint_sub_bigint_underflow(void);
int		test_bigint_sub_int(void);
int		test_bigint_sub_int_null(void);
int		test_bigint_sub_int_carry(void);
int		test_bigint_sub_int_underflow(void);

#endif