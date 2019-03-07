# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bigint                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 14:38:00 by apion             #+#    #+#              #
#    Updated: 2019/03/07 18:23:23 by apion            ###   ########.fr        #
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

C_FILES_BIGINT_ADD		:= test_bigint/test_add/00_launcher.c
C_FILES_BIGINT_ADD_BIGINT	:= test_bigint/test_add/test_add_bigint/00_launcher.c \
	test_bigint/test_add/test_add_bigint/01_test_bigint_add_bigint.c \
	test_bigint/test_add/test_add_bigint/02_test_bigint_add_bigint_self.c \
	test_bigint/test_add/test_add_bigint/03_test_bigint_add_bigint_null.c \
	test_bigint/test_add/test_add_bigint/04_test_bigint_add_bigint_carry.c \
	test_bigint/test_add/test_add_bigint/05_test_bigint_add_bigint_overflow.c \
	test_bigint/test_add/test_add_bigint/06_test_bigint_add_int.c \
	test_bigint/test_add/test_add_bigint/07_test_bigint_add_int_null.c \
	test_bigint/test_add/test_add_bigint/08_test_bigint_add_int_carry.c \
	test_bigint/test_add/test_add_bigint/09_test_bigint_add_int_overflow.c
C_FILES_BIGINT_ADD_SELF		:= test_bigint/test_add/test_add_self/00_launcher.c \
	test_bigint/test_add/test_add_self/01_test_bigint_add_bigint.c \
	test_bigint/test_add/test_add_self/02_test_bigint_add_bigint_self.c \
	test_bigint/test_add/test_add_self/03_test_bigint_add_bigint_null.c \
	test_bigint/test_add/test_add_self/04_test_bigint_add_bigint_carry.c \
	test_bigint/test_add/test_add_self/05_test_bigint_add_bigint_overflow.c \
	test_bigint/test_add/test_add_self/06_test_bigint_add_int.c \
	test_bigint/test_add/test_add_self/07_test_bigint_add_int_null.c \
	test_bigint/test_add/test_add_self/08_test_bigint_add_int_carry.c \
	test_bigint/test_add/test_add_self/09_test_bigint_add_int_overflow.c

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

C_FILES_BIGINT_MULT		:= test_bigint/test_mult/00_launcher.c
C_FILES_BIGINT_MULT_BIGINT	:= test_bigint/test_mult/test_mult_bigint/00_launcher.c \
	test_bigint/test_mult/test_mult_bigint/01_test_bigint_mult_int_one.c \
	test_bigint/test_mult/test_mult_bigint/02_test_bigint_mult_int_small.c \
	test_bigint/test_mult/test_mult_bigint/03_test_bigint_mult_int_medium.c \
	test_bigint/test_mult/test_mult_bigint/04_test_bigint_mult_by_basis.c \
	test_bigint/test_mult/test_mult_bigint/05_test_bigint_mult.c
C_FILES_BIGINT_MULT_SELF	:= test_bigint/test_mult/test_mult_self/00_launcher.c \
	test_bigint/test_mult/test_mult_self/01_test_bigint_mult_int_one.c \
	test_bigint/test_mult/test_mult_self/02_test_bigint_mult_int_small.c \
	test_bigint/test_mult/test_mult_self/03_test_bigint_mult_int_medium.c \
	test_bigint/test_mult/test_mult_self/04_test_bigint_mult_by_basis.c \
	test_bigint/test_mult/test_mult_self/05_test_bigint_mult.c

C_FILES_BIGINT		+= $(C_FILES_BIGINT_INIT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_CMP)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_UTILS)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_ADD)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_ADD_BIGINT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_ADD_SELF)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_SHIFT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_SUB)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_MULT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_MULT_BIGINT)
C_FILES_BIGINT		+= $(C_FILES_BIGINT_MULT_SELF)
