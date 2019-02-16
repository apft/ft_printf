# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bigint                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 14:38:00 by apion             #+#    #+#              #
#    Updated: 2019/02/16 14:21:57 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES_BIGINT		:= test_bigint/00_launcher.c

C_FILES_BIGINT_CMP	:= test_bigint/test_cmp/00_launcher.c \
	test_bigint/test_cmp/01_test_bigint_cmp_equal.c \
	test_bigint/test_cmp/02_test_bigint_cmp_inf.c \
	test_bigint/test_cmp/03_test_bigint_cmp_sup.c \
	test_bigint/test_cmp/04_test_bigint_cmp_length_inf.c \
	test_bigint/test_cmp/05_test_bigint_cmp_length_sup.c \
	test_bigint/test_cmp/06_test_bigint_cmp_equal_null.c

C_FILES_BIGINT_INIT	:= test_bigint/test_init/00_launcher.c \
	test_bigint/test_init/01_test_bigint_init_null.c \
	test_bigint/test_init/02_test_bigint_init_int.c \
	test_bigint/test_init/03_test_bigint_init_int_null.c \
	test_bigint/test_init/04_test_bigint_init_int_max.c

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

C_FILES_BIGINT_SHIFT	:= test_bigint/test_shift/00_launcher.c \
	test_bigint/test_shift/test_shift_left/00_launcher.c \
	test_bigint/test_shift/test_shift_left/01_test_bigint_shift_left_null.c \
	test_bigint/test_shift/test_shift_left/02_test_bigint_shift_left_one.c \
	test_bigint/test_shift/test_shift_left/03_test_bigint_shift_left_pos.c \
	test_bigint/test_shift/test_shift_left/04_test_bigint_shift_left_block.c \
	test_bigint/test_shift/test_shift_left/05_test_bigint_shift_left_few_blocks.c \
	test_bigint/test_shift/test_shift_left/06_test_bigint_shift_left_overflow.c

C_FILES_BIGINT		+= $(C_FILES_BIGINT_INIT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_CMP)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_ADD)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_SHIFT)
