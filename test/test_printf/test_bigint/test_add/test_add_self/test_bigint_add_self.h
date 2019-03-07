/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bigint_add_self.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:02:24 by apion             #+#    #+#             */
/*   Updated: 2019/03/07 18:15:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BIGINT_ADD_SELF_H
# define TEST_BIGINT_ADD_SELF_H

int		test_bigint_add_self_bigint(void);
int		test_bigint_add_self_bigint_self(void);
int		test_bigint_add_self_bigint_null(void);
int		test_bigint_add_self_bigint_carry(void);
int		test_bigint_add_self_bigint_overflow(void);
int		test_bigint_add_self_int(void);
int		test_bigint_add_self_int_null(void);
int		test_bigint_add_self_int_carry(void);
int		test_bigint_add_self_int_overflow(void);

#endif
