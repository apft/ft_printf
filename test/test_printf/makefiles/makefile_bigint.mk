# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bigint                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 14:38:00 by apion             #+#    #+#              #
#    Updated: 2019/03/05 19:18:49 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES_BIGINT			:= test_bigint/00_launcher.c

C_FILES_BIGINT_CMP		:= test_bigint/test_cmp/00_launcher.c \
	test_bigint/test_cmp/01_test_bigint_cmp_equal.c \
	test_bigint/test_cmp/02_test_bigint_cmp_inf.c \
	test_bigint/test_cmp/03_test_bigint_cmp_sup.c \
	test_bigint/test_cmp/04_test_bigint_cmp_length_inf.c \
	test_bigint/test_cmp/05_test_bigint_cmp_length_sup.c \
	test_bigint/test_cmp/06_test_bigint_cmp_equal_null.c

C_FILES_BIGINT_INIT		:= test_bigint/test_init/00_launcher.c \
	test_bigint/test_init/01_test_bigint_init_null.c \
	test_bigint/test_init/02_test_bigint_init_int.c \
	test_bigint/test_init/03_test_bigint_init_int_null.c \
	test_bigint/test_init/04_test_bigint_init_int_max.c

C_FILES_BIGINT_UTILS	:= test_bigint/test_utils/00_launcher.c \
	test_bigint/test_utils/01_test_bigint_is_overflow.c \
	test_bigint/test_utils/02_test_bigint_is_overflow_false.c \
	test_bigint/test_utils/03_test_bigint_is_underflow.c \
	test_bigint/test_utils/04_test_bigint_is_underflow_false.c

C_FILES_BIGINT_ADD		:= test_bigint/test_add/00_launcher.c \
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
	test_bigint/test_shift/test_shift_left/06_test_bigint_shift_left_overflow.c \
	test_bigint/test_shift/test_shift_left_self/00_launcher.c \
	test_bigint/test_shift/test_shift_left_self/01_test_bigint_shift_left_null_self.c \
	test_bigint/test_shift/test_shift_left_self/02_test_bigint_shift_left_one_self.c \
	test_bigint/test_shift/test_shift_left_self/03_test_bigint_shift_left_pos_self.c \
	test_bigint/test_shift/test_shift_left_self/04_test_bigint_shift_left_block_self.c \
	test_bigint/test_shift/test_shift_left_self/05_test_bigint_shift_left_few_blocks_self.c \
	test_bigint/test_shift/test_shift_left_self/06_test_bigint_shift_left_overflow_self.c

C_FILES_BIGINT_SUB		:= test_bigint/test_sub/00_launcher.c \
	test_bigint/test_sub/01_test_bigint_sub_bigint.c \
	test_bigint/test_sub/02_test_bigint_sub_bigint_self.c \
	test_bigint/test_sub/03_test_bigint_sub_bigint_null.c \
	test_bigint/test_sub/04_test_bigint_sub_bigint_carry.c \
	test_bigint/test_sub/05_test_bigint_sub_bigint_underflow.c \
	test_bigint/test_sub/06_test_bigint_sub_int.c \
	test_bigint/test_sub/07_test_bigint_sub_int_null.c \
	test_bigint/test_sub/08_test_bigint_sub_int_carry.c \
	test_bigint/test_sub/09_test_bigint_sub_int_underflow.c

C_FILES_BIGINT_MULT		:= test_bigint/test_mult/00_launcher.c \
	test_bigint/test_mult/01_test_bigint_mult_int_one.c \
	test_bigint/test_mult/02_test_bigint_mult_int_small.c \
	test_bigint/test_mult/03_test_bigint_mult_int_medium.c

C_FILES_BIGINT		+= $(C_FILES_BIGINT_INIT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_CMP)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_UTILS)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_ADD)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_SHIFT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_SUB)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_MULT)
