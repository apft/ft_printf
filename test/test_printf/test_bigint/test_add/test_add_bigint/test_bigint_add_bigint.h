/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_add_bigint.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:24 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:15:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_ADD_BIGINT_H
# define TEST_BIGINT_ADD_BIGINT_H

int		test_bigint_add_bigint(void);
int		test_bigint_add_bigint_self(void);
int		test_bigint_add_bigint_null(void);
int		test_bigint_add_bigint_carry(void);
int		test_bigint_add_bigint_overflow(void);
int		test_bigint_add_int(void);
int		test_bigint_add_int_null(void);
int		test_bigint_add_int_carry(void);
int		test_bigint_add_int_overflow(void);

#endif
