# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bigint                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 14:38:00 by apion             #+#    #+#              #
#    Updated: 2019/02/15 17:12:07 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES_BIGINT		:= test_bigint/test_bigint.c

C_FILES_BIGINT_CMP	:= test_bigint/test_cmp/00_launcher.c \
						test_bigint/test_cmp/01_test_bigint_cmp_equal.c \
						test_bigint/test_cmp/02_test_bigint_cmp_inf.c \
						test_bigint/test_cmp/03_test_bigint_cmp_sup.c \
						test_bigint/test_cmp/04_test_bigint_cmp_length_inf.c \
						test_bigint/test_cmp/05_test_bigint_cmp_length_sup.c \
						test_bigint/test_cmp/06_test_bigint_cmp_equal_null.c

C_FILES_BIGINT_INIT	:= test_bigint/test_init/00_launcher.c

C_FILES_BIGINT_ADD	:= test_bigint/test_add/00_launcher.c \
						test_bigint/test_add/01_test_bigint_add_bigint.c \
						test_bigint/test_add/02_test_bigint_add_bigint_self.c \
						test_bigint/test_add/03_test_bigint_add_bigint_null.c \
						test_bigint/test_add/04_test_bigint_add_bigint_carry.c \
						test_bigint/test_add/05_test_bigint_add_bigint_overflow.c \
						test_bigint/test_add/06_test_bigint_add_int.c \
						test_bigint/test_add/07_test_bigint_add_int_null.c \
						test_bigint/test_add/08_test_bigint_add_int_carry.c \
						test_bigint/test_add/09_test_bigint_add_int_overflow.c

C_FILES_BIGINT		+= $(C_FILES_BIGINT_CMP) $(C_FILES_BIGINT_ADD)
