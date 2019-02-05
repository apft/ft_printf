# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2019/02/05 20:16:56 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPRINTF_PATH		:= ../../
FTPRINTF_LIB		:= $(FTPRINTF_PATH)libftprintf.a

SHELL				:= /bin/sh
RM					:= /bin/rm -f
MAKE				:= make
CC					:= gcc
ifndef NOERR
CFLAGS				:= -Wall -Wextra -Werror
endif
CINCLUDES			= $(addprefix -I,$(H_DIR))
CPPFLAGS			= -MMD -MP -MF $(D_DIR)$*.d

LIBUNIT_NAME		= libunit.a
LIBUNIT_PATH		= ../framework
LIBUNIT				= $(LIBUNIT_PATH)/$(LIBUNIT_NAME)

NAME				= $(EXEC).out
EXEC				= test
C_DIR				=
H_DIR				= . $(LIBUNIT_PATH)
D_DIR				= .dep/
O_DIR				= .obj/
C_FILES				:= main.c \
						utils.c \
						test_int/001_test_int_null_d_0_0.c \
						test_int/002_test_int_pos_d_0_0.c \
						test_int/003_test_int_neg_d_0_0.c \
						test_int/004_test_int_min_d_0_0.c \
						test_int/005_test_int_max_d_0_0.c \
						test_int/006_test_long_min_d_0_0.c \
						test_int/007_test_long_max_d_0_0.c \
						test_int/008_test_long_long_min_d_0_0.c \
						test_int/009_test_long_long_max_d_0_0.c \
						test_int/00_launcher.c \
						test_int/010_test_long_long_d_0_0.c \
						test_int/011_test_int_null_i_0_0.c \
						test_int/012_test_int_pos_i_0_0.c \
						test_int/013_test_int_neg_i_0_0.c \
						test_int/014_test_int_min_i_0_0.c \
						test_int/015_test_int_max_i_0_0.c \
						test_int/016_test_long_min_i_0_0.c \
						test_int/017_test_long_max_i_0_0.c \
						test_int/018_test_long_long_min_i_0_0.c \
						test_int/019_test_long_long_max_i_0_0.c \
						test_int/020_test_long_long_i_0_0.c \
						test_int/021_test_int_null_d_1_1.c \
						test_int/022_test_int_pos_d_1_1.c \
						test_int/023_test_int_neg_d_1_1.c \
						test_int/024_test_int_min_d_1_1.c \
						test_int/025_test_int_max_d_1_1.c \
						test_int/026_test_long_min_d_1_1.c \
						test_int/027_test_long_max_d_1_1.c \
						test_int/028_test_long_long_min_d_1_1.c \
						test_int/029_test_long_long_max_d_1_1.c \
						test_int/030_test_long_long_d_1_1.c \
						test_int/031_test_int_null_d_2_2.c \
						test_int/032_test_int_pos_d_2_2.c \
						test_int/033_test_int_neg_d_2_2.c \
						test_int/034_test_int_min_d_2_2.c \
						test_int/035_test_int_max_d_2_2.c \
						test_int/036_test_long_min_d_2_2.c \
						test_int/037_test_long_max_d_2_2.c \
						test_int/038_test_long_long_min_d_2_2.c \
						test_int/039_test_long_long_max_d_2_2.c \
						test_int/040_test_long_long_d_2_2.c \
						test_int/041_test_int_null_d_3_3.c \
						test_int/042_test_int_pos_d_3_3.c \
						test_int/043_test_int_neg_d_3_3.c \
						test_int/044_test_int_min_d_3_3.c \
						test_int/045_test_int_max_d_3_3.c \
						test_int/046_test_long_min_d_3_3.c \
						test_int/047_test_long_max_d_3_3.c \
						test_int/048_test_long_long_min_d_3_3.c \
						test_int/049_test_long_long_max_d_3_3.c \
						test_int/050_test_long_long_d_3_3.c \
						test_int/051_test_int_null_d_4_4.c \
						test_int/052_test_int_pos_d_4_4.c \
						test_int/053_test_int_neg_d_4_4.c \
						test_int/054_test_int_min_d_4_4.c \
						test_int/055_test_int_max_d_4_4.c \
						test_int/056_test_long_min_d_4_4.c \
						test_int/057_test_long_max_d_4_4.c \
						test_int/058_test_long_long_min_d_4_4.c \
						test_int/059_test_long_long_max_d_4_4.c \
						test_int/060_test_long_long_d_4_4.c \
						test_int/061_test_int_null_ld_0_0.c \
						test_int/062_test_int_pos_ld_0_0.c \
						test_int/063_test_int_neg_ld_0_0.c \
						test_int/064_test_int_min_ld_0_0.c \
						test_int/065_test_int_max_ld_0_0.c \
						test_int/066_test_long_min_ld_0_0.c \
						test_int/067_test_long_max_ld_0_0.c \
						test_int/068_test_long_long_min_ld_0_0.c \
						test_int/069_test_long_long_max_ld_0_0.c \
						test_int/070_test_long_long_ld_0_0.c \
						test_int/071_test_int_null_ld_1_1.c \
						test_int/072_test_int_pos_ld_1_1.c \
						test_int/073_test_int_neg_ld_1_1.c \
						test_int/074_test_int_min_ld_1_1.c \
						test_int/075_test_int_max_ld_1_1.c \
						test_int/076_test_long_min_ld_1_1.c \
						test_int/077_test_long_max_ld_1_1.c \
						test_int/078_test_long_long_min_ld_1_1.c \
						test_int/079_test_long_long_max_ld_1_1.c \
						test_int/080_test_long_long_ld_1_1.c \
						test_int/081_test_int_null_ld_2_2.c \
						test_int/082_test_int_pos_ld_2_2.c \
						test_int/083_test_int_neg_ld_2_2.c \
						test_int/084_test_int_min_ld_2_2.c \
						test_int/085_test_int_max_ld_2_2.c \
						test_int/086_test_long_min_ld_2_2.c \
						test_int/087_test_long_max_ld_2_2.c \
						test_int/088_test_long_long_min_ld_2_2.c \
						test_int/089_test_long_long_max_ld_2_2.c \
						test_int/090_test_long_long_ld_2_2.c \
						test_int/091_test_int_null_lld_0_0.c \
						test_int/092_test_int_pos_lld_0_0.c \
						test_int/093_test_int_neg_lld_0_0.c \
						test_int/094_test_int_min_lld_0_0.c \
						test_int/095_test_int_max_lld_0_0.c \
						test_int/096_test_long_min_lld_0_0.c \
						test_int/097_test_long_max_lld_0_0.c \
						test_int/098_test_long_long_min_lld_0_0.c \
						test_int/099_test_long_long_max_lld_0_0.c \
						test_int/100_test_long_long_lld_0_0.c \
						test_int/101_test_int_null_lld_1_1.c \
						test_int/102_test_int_pos_lld_1_1.c \
						test_int/103_test_int_neg_lld_1_1.c \
						test_int/104_test_int_min_lld_1_1.c \
						test_int/105_test_int_max_lld_1_1.c \
						test_int/106_test_long_min_lld_1_1.c \
						test_int/107_test_long_max_lld_1_1.c \
						test_int/108_test_long_long_min_lld_1_1.c \
						test_int/109_test_long_long_max_lld_1_1.c \
						test_int/110_test_long_long_lld_1_1.c \
						test_int/111_test_int_null_lld_2_2.c \
						test_int/112_test_int_pos_lld_2_2.c \
						test_int/113_test_int_neg_lld_2_2.c \
						test_int/114_test_int_min_lld_2_2.c \
						test_int/115_test_int_max_lld_2_2.c \
						test_int/116_test_long_min_lld_2_2.c \
						test_int/117_test_long_max_lld_2_2.c \
						test_int/118_test_long_long_min_lld_2_2.c \
						test_int/119_test_long_long_max_lld_2_2.c \
						test_int/120_test_long_long_lld_2_2.c \
						test_int/121_test_int_null_u_0_0.c \
						test_int/122_test_int_pos_u_0_0.c \
						test_int/123_test_int_neg_u_0_0.c \
						test_int/124_test_int_min_u_0_0.c \
						test_int/125_test_int_max_u_0_0.c \
						test_int/126_test_long_min_u_0_0.c \
						test_int/127_test_long_max_u_0_0.c \
						test_int/128_test_long_long_min_u_0_0.c \
						test_int/129_test_long_long_max_u_0_0.c \
						test_int/130_test_long_long_u_0_0.c \
						test_int/131_test_int_null_lu_0_0.c \
						test_int/132_test_int_pos_lu_0_0.c \
						test_int/133_test_int_neg_lu_0_0.c \
						test_int/134_test_int_min_lu_0_0.c \
						test_int/135_test_int_max_lu_0_0.c \
						test_int/136_test_long_min_lu_0_0.c \
						test_int/137_test_long_max_lu_0_0.c \
						test_int/138_test_long_long_min_lu_0_0.c \
						test_int/139_test_long_long_max_lu_0_0.c \
						test_int/140_test_long_long_lu_0_0.c \
						test_int/141_test_int_null_llu_0_0.c \
						test_int/142_test_int_pos_llu_0_0.c \
						test_int/143_test_int_neg_llu_0_0.c \
						test_int/144_test_int_min_llu_0_0.c \
						test_int/145_test_int_max_llu_0_0.c \
						test_int/146_test_long_min_llu_0_0.c \
						test_int/147_test_long_max_llu_0_0.c \
						test_int/148_test_long_long_min_llu_0_0.c \
						test_int/149_test_long_long_max_llu_0_0.c \
						test_int/150_test_long_long_llu_0_0.c \
						test_int/151_test_int_null_x_0_0.c \
						test_int/152_test_int_pos_x_0_0.c \
						test_int/153_test_int_neg_x_0_0.c \
						test_int/154_test_int_min_x_0_0.c \
						test_int/155_test_int_max_x_0_0.c \
						test_int/156_test_long_min_x_0_0.c \
						test_int/157_test_long_max_x_0_0.c \
						test_int/158_test_long_long_min_x_0_0.c \
						test_int/159_test_long_long_max_x_0_0.c \
						test_int/160_test_long_long_x_0_0.c \
						test_int/161_test_int_null_x_1_1.c \
						test_int/162_test_int_pos_x_1_1.c \
						test_int/163_test_int_neg_x_1_1.c \
						test_int/164_test_int_min_x_1_1.c \
						test_int/165_test_int_max_x_1_1.c \
						test_int/166_test_long_min_x_1_1.c \
						test_int/167_test_long_max_x_1_1.c \
						test_int/168_test_long_long_min_x_1_1.c \
						test_int/169_test_long_long_max_x_1_1.c \
						test_int/170_test_long_long_x_1_1.c \
						test_int/171_test_int_null_x_2_2.c \
						test_int/172_test_int_pos_x_2_2.c \
						test_int/173_test_int_neg_x_2_2.c \
						test_int/174_test_int_min_x_2_2.c \
						test_int/175_test_int_max_x_2_2.c \
						test_int/176_test_long_min_x_2_2.c \
						test_int/177_test_long_max_x_2_2.c \
						test_int/178_test_long_long_min_x_2_2.c \
						test_int/179_test_long_long_max_x_2_2.c \
						test_int/180_test_long_long_x_2_2.c \
						test_int/181_test_int_null_X_0_0.c \
						test_int/182_test_int_pos_X_0_0.c \
						test_int/183_test_int_neg_X_0_0.c \
						test_int/184_test_int_min_X_0_0.c \
						test_int/185_test_int_max_X_0_0.c \
						test_int/186_test_long_min_X_0_0.c \
						test_int/187_test_long_max_X_0_0.c \
						test_int/188_test_long_long_min_X_0_0.c \
						test_int/189_test_long_long_max_X_0_0.c \
						test_int/190_test_long_long_X_0_0.c \
						test_int/191_test_int_null_X_1_1.c \
						test_int/192_test_int_pos_X_1_1.c \
						test_int/193_test_int_neg_X_1_1.c \
						test_int/194_test_int_min_X_1_1.c \
						test_int/195_test_int_max_X_1_1.c \
						test_int/196_test_long_min_X_1_1.c \
						test_int/197_test_long_max_X_1_1.c \
						test_int/198_test_long_long_min_X_1_1.c \
						test_int/199_test_long_long_max_X_1_1.c \
						test_int/200_test_long_long_X_1_1.c \
						test_int/201_test_int_null_X_2_2.c \
						test_int/202_test_int_pos_X_2_2.c \
						test_int/203_test_int_neg_X_2_2.c \
						test_int/204_test_int_min_X_2_2.c \
						test_int/205_test_int_max_X_2_2.c \
						test_int/206_test_long_min_X_2_2.c \
						test_int/207_test_long_max_X_2_2.c \
						test_int/208_test_long_long_min_X_2_2.c \
						test_int/209_test_long_long_max_X_2_2.c \
						test_int/210_test_long_long_X_2_2.c \
						test_int/211_test_int_null_o_0_0.c \
						test_int/212_test_int_pos_o_0_0.c \
						test_int/213_test_int_neg_o_0_0.c \
						test_int/214_test_int_min_o_0_0.c \
						test_int/215_test_int_max_o_0_0.c \
						test_int/216_test_long_min_o_0_0.c \
						test_int/217_test_long_max_o_0_0.c \
						test_int/218_test_long_long_min_o_0_0.c \
						test_int/219_test_long_long_max_o_0_0.c \
						test_int/220_test_long_long_o_0_0.c \
						test_int/221_test_int_null_o_1_1.c \
						test_int/222_test_int_pos_o_1_1.c \
						test_int/223_test_int_neg_o_1_1.c \
						test_int/224_test_int_min_o_1_1.c \
						test_int/225_test_int_max_o_1_1.c \
						test_int/226_test_long_min_o_1_1.c \
						test_int/227_test_long_max_o_1_1.c \
						test_int/228_test_long_long_min_o_1_1.c \
						test_int/229_test_long_long_max_o_1_1.c \
						test_int/230_test_long_long_o_1_1.c \
						test_int/231_test_int_null_o_2_2.c \
						test_int/232_test_int_pos_o_2_2.c \
						test_int/233_test_int_neg_o_2_2.c \
						test_int/234_test_int_min_o_2_2.c \
						test_int/235_test_int_max_o_2_2.c \
						test_int/236_test_long_min_o_2_2.c \
						test_int/237_test_long_max_o_2_2.c \
						test_int/238_test_long_long_min_o_2_2.c \
						test_int/239_test_long_long_max_o_2_2.c \
						test_int/240_test_long_long_o_2_2.c \
						test_float_hexa/001_test_float_hexa_null_a_0_0.c \
						test_float_hexa/002_test_float_hexa_null_neg_a_0_0.c \
						test_float_hexa/003_test_float_hexa_pos_one_a_0_0.c \
						test_float_hexa/004_test_float_hexa_pos_two_a_0_0.c \
						test_float_hexa/005_test_float_hexa_neg_a_0_0.c \
						test_float_hexa/006_test_float_hexa_inf_one_a_0_0.c \
						test_float_hexa/007_test_float_hexa_inf_zero_one_a_0_0.c \
						test_float_hexa/008_test_float_hexa_den_a_0_0.c \
						test_float_hexa/009_test_float_hexa_round_even_top_a_0_0.c \
						test_float_hexa/00_launcher.c \
						test_float_hexa/010_test_float_hexa_round_even_down_a_0_0.c \
						test_float_hexa/011_test_float_hexa_round_even_top_neg_a_0_0.c \
						test_float_hexa/012_test_float_hexa_round_even_down_neg_a_0_0.c \
						test_float_hexa/013_test_float_hexa_null_a_1_1.c \
						test_float_hexa/014_test_float_hexa_null_neg_a_1_1.c \
						test_float_hexa/015_test_float_hexa_pos_one_a_1_1.c \
						test_float_hexa/016_test_float_hexa_pos_two_a_1_1.c \
						test_float_hexa/017_test_float_hexa_neg_a_1_1.c \
						test_float_hexa/018_test_float_hexa_inf_one_a_1_1.c \
						test_float_hexa/019_test_float_hexa_inf_zero_one_a_1_1.c \
						test_float_hexa/020_test_float_hexa_den_a_1_1.c \
						test_float_hexa/021_test_float_hexa_round_even_top_a_1_1.c \
						test_float_hexa/022_test_float_hexa_round_even_down_a_1_1.c \
						test_float_hexa/023_test_float_hexa_round_even_top_neg_a_1_1.c \
						test_float_hexa/024_test_float_hexa_round_even_down_neg_a_1_1.c \
						test_float_hexa/025_test_float_hexa_null_a_2_2.c \
						test_float_hexa/026_test_float_hexa_null_neg_a_2_2.c \
						test_float_hexa/027_test_float_hexa_pos_one_a_2_2.c \
						test_float_hexa/028_test_float_hexa_pos_two_a_2_2.c \
						test_float_hexa/029_test_float_hexa_neg_a_2_2.c \
						test_float_hexa/030_test_float_hexa_inf_one_a_2_2.c \
						test_float_hexa/031_test_float_hexa_inf_zero_one_a_2_2.c \
						test_float_hexa/032_test_float_hexa_den_a_2_2.c \
						test_float_hexa/033_test_float_hexa_round_even_top_a_2_2.c \
						test_float_hexa/034_test_float_hexa_round_even_down_a_2_2.c \
						test_float_hexa/035_test_float_hexa_round_even_top_neg_a_2_2.c \
						test_float_hexa/036_test_float_hexa_round_even_down_neg_a_2_2.c \
						test_float_hexa/037_test_float_hexa_null_a_3_3.c \
						test_float_hexa/038_test_float_hexa_null_neg_a_3_3.c \
						test_float_hexa/039_test_float_hexa_pos_one_a_3_3.c \
						test_float_hexa/040_test_float_hexa_pos_two_a_3_3.c \
						test_float_hexa/041_test_float_hexa_neg_a_3_3.c \
						test_float_hexa/042_test_float_hexa_inf_one_a_3_3.c \
						test_float_hexa/043_test_float_hexa_inf_zero_one_a_3_3.c \
						test_float_hexa/044_test_float_hexa_den_a_3_3.c \
						test_float_hexa/045_test_float_hexa_round_even_top_a_3_3.c \
						test_float_hexa/046_test_float_hexa_round_even_down_a_3_3.c \
						test_float_hexa/047_test_float_hexa_round_even_top_neg_a_3_3.c \
						test_float_hexa/048_test_float_hexa_round_even_down_neg_a_3_3.c \
						test_float_hexa/049_test_float_hexa_null_a_4_4.c \
						test_float_hexa/050_test_float_hexa_null_neg_a_4_4.c \
						test_float_hexa/051_test_float_hexa_pos_one_a_4_4.c \
						test_float_hexa/052_test_float_hexa_pos_two_a_4_4.c \
						test_float_hexa/053_test_float_hexa_neg_a_4_4.c \
						test_float_hexa/054_test_float_hexa_inf_one_a_4_4.c \
						test_float_hexa/055_test_float_hexa_inf_zero_one_a_4_4.c \
						test_float_hexa/056_test_float_hexa_den_a_4_4.c \
						test_float_hexa/057_test_float_hexa_round_even_top_a_4_4.c \
						test_float_hexa/058_test_float_hexa_round_even_down_a_4_4.c \
						test_float_hexa/059_test_float_hexa_round_even_top_neg_a_4_4.c \
						test_float_hexa/060_test_float_hexa_round_even_down_neg_a_4_4.c \
						test_float_hexa/061_test_float_hexa_null_a_5_5.c \
						test_float_hexa/062_test_float_hexa_null_neg_a_5_5.c \
						test_float_hexa/063_test_float_hexa_pos_one_a_5_5.c \
						test_float_hexa/064_test_float_hexa_pos_two_a_5_5.c \
						test_float_hexa/065_test_float_hexa_neg_a_5_5.c \
						test_float_hexa/066_test_float_hexa_inf_one_a_5_5.c \
						test_float_hexa/067_test_float_hexa_inf_zero_one_a_5_5.c \
						test_float_hexa/068_test_float_hexa_den_a_5_5.c \
						test_float_hexa/069_test_float_hexa_round_even_top_a_5_5.c \
						test_float_hexa/070_test_float_hexa_round_even_down_a_5_5.c \
						test_float_hexa/071_test_float_hexa_round_even_top_neg_a_5_5.c \
						test_float_hexa/072_test_float_hexa_round_even_down_neg_a_5_5.c \
						test_float_hexa/073_test_float_hexa_null_A_0_0.c \
						test_float_hexa/074_test_float_hexa_null_neg_A_0_0.c \
						test_float_hexa/075_test_float_hexa_pos_one_A_0_0.c \
						test_float_hexa/076_test_float_hexa_pos_two_A_0_0.c \
						test_float_hexa/077_test_float_hexa_neg_A_0_0.c \
						test_float_hexa/078_test_float_hexa_inf_one_A_0_0.c \
						test_float_hexa/079_test_float_hexa_inf_zero_one_A_0_0.c \
						test_float_hexa/080_test_float_hexa_den_A_0_0.c \
						test_float_hexa/081_test_float_hexa_round_even_top_A_0_0.c \
						test_float_hexa/082_test_float_hexa_round_even_down_A_0_0.c \
						test_float_hexa/083_test_float_hexa_round_even_top_neg_A_0_0.c \
						test_float_hexa/084_test_float_hexa_round_even_down_neg_A_0_0.c \
						test_float_hexa/085_test_float_hexa_null_A_1_1.c \
						test_float_hexa/086_test_float_hexa_null_neg_A_1_1.c \
						test_float_hexa/087_test_float_hexa_pos_one_A_1_1.c \
						test_float_hexa/088_test_float_hexa_pos_two_A_1_1.c \
						test_float_hexa/089_test_float_hexa_neg_A_1_1.c \
						test_float_hexa/090_test_float_hexa_inf_one_A_1_1.c \
						test_float_hexa/091_test_float_hexa_inf_zero_one_A_1_1.c \
						test_float_hexa/092_test_float_hexa_den_A_1_1.c \
						test_float_hexa/093_test_float_hexa_round_even_top_A_1_1.c \
						test_float_hexa/094_test_float_hexa_round_even_down_A_1_1.c \
						test_float_hexa/095_test_float_hexa_round_even_top_neg_A_1_1.c \
						test_float_hexa/096_test_float_hexa_round_even_down_neg_A_1_1.c \
						test_float_hexa/097_test_float_hexa_null_A_2_2.c \
						test_float_hexa/098_test_float_hexa_null_neg_A_2_2.c \
						test_float_hexa/099_test_float_hexa_pos_one_A_2_2.c \
						test_float_hexa/100_test_float_hexa_pos_two_A_2_2.c \
						test_float_hexa/101_test_float_hexa_neg_A_2_2.c \
						test_float_hexa/102_test_float_hexa_inf_one_A_2_2.c \
						test_float_hexa/103_test_float_hexa_inf_zero_one_A_2_2.c \
						test_float_hexa/104_test_float_hexa_den_A_2_2.c \
						test_float_hexa/105_test_float_hexa_round_even_top_A_2_2.c \
						test_float_hexa/106_test_float_hexa_round_even_down_A_2_2.c \
						test_float_hexa/107_test_float_hexa_round_even_top_neg_A_2_2.c \
						test_float_hexa/108_test_float_hexa_round_even_down_neg_A_2_2.c \
						test_float_hexa/109_test_float_hexa_null_A_3_3.c \
						test_float_hexa/110_test_float_hexa_null_neg_A_3_3.c \
						test_float_hexa/111_test_float_hexa_pos_one_A_3_3.c \
						test_float_hexa/112_test_float_hexa_pos_two_A_3_3.c \
						test_float_hexa/113_test_float_hexa_neg_A_3_3.c \
						test_float_hexa/114_test_float_hexa_inf_one_A_3_3.c \
						test_float_hexa/115_test_float_hexa_inf_zero_one_A_3_3.c \
						test_float_hexa/116_test_float_hexa_den_A_3_3.c \
						test_float_hexa/117_test_float_hexa_round_even_top_A_3_3.c \
						test_float_hexa/118_test_float_hexa_round_even_down_A_3_3.c \
						test_float_hexa/119_test_float_hexa_round_even_top_neg_A_3_3.c \
						test_float_hexa/120_test_float_hexa_round_even_down_neg_A_3_3.c \
						test_float_hexa/121_test_float_hexa_null_A_4_4.c \
						test_float_hexa/122_test_float_hexa_null_neg_A_4_4.c \
						test_float_hexa/123_test_float_hexa_pos_one_A_4_4.c \
						test_float_hexa/124_test_float_hexa_pos_two_A_4_4.c \
						test_float_hexa/125_test_float_hexa_neg_A_4_4.c \
						test_float_hexa/126_test_float_hexa_inf_one_A_4_4.c \
						test_float_hexa/127_test_float_hexa_inf_zero_one_A_4_4.c \
						test_float_hexa/128_test_float_hexa_den_A_4_4.c \
						test_float_hexa/129_test_float_hexa_round_even_top_A_4_4.c \
						test_float_hexa/130_test_float_hexa_round_even_down_A_4_4.c \
						test_float_hexa/131_test_float_hexa_round_even_top_neg_A_4_4.c \
						test_float_hexa/132_test_float_hexa_round_even_down_neg_A_4_4.c \
						test_float_hexa/133_test_float_hexa_null_A_5_5.c \
						test_float_hexa/134_test_float_hexa_null_neg_A_5_5.c \
						test_float_hexa/135_test_float_hexa_pos_one_A_5_5.c \
						test_float_hexa/136_test_float_hexa_pos_two_A_5_5.c \
						test_float_hexa/137_test_float_hexa_neg_A_5_5.c \
						test_float_hexa/138_test_float_hexa_inf_one_A_5_5.c \
						test_float_hexa/139_test_float_hexa_inf_zero_one_A_5_5.c \
						test_float_hexa/140_test_float_hexa_den_A_5_5.c \
						test_float_hexa/141_test_float_hexa_round_even_top_A_5_5.c \
						test_float_hexa/142_test_float_hexa_round_even_down_A_5_5.c \
						test_float_hexa/143_test_float_hexa_round_even_top_neg_A_5_5.c \
						test_float_hexa/144_test_float_hexa_round_even_down_neg_A_5_5.c
O_FILES			:= $(C_FILES:%.c=%.o)
D_FILES			:= $(C_FILES:%.c=%.d)
DIRS			:= $(strip $(filter-out ./,$(sort $(dir $(C_FILES))))) .

.SUFFIXES:
.SUFFIXES: .c .o .d

.PHONY: all
all: $(NAME)

.PHONY: $(FTPRINTF_LIB)
$(FTPRINTF_LIB):
	make -C $(FTPRINTF_PATH)

.PHONY: $(LIBUNIT)
$(LIBUNIT):
	make -C $(LIBUNIT_PATH)

$(NAME): $(addprefix $(O_DIR), $(O_FILES)) $(LIBUNIT) $(FTPRINTF_LIB)
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^

.PHONY: $(EXEC)
$(EXEC): all
	clear
	@./$(NAME) || true

$(O_DIR)%.o: %.c
$(O_DIR)%.o: %.c $(D_DIR)%.d | $(addprefix $(O_DIR), $(DIRS)) $(addprefix $(D_DIR), $(DIRS))
	$(CC) $(CFLAGS) $(CINCLUDES) $(CPPFLAGS) -o $@ -c $<

$(D_DIR)%.d: ;
.PRECIOUS: $(D_DIR)%.d

$(addprefix $(O_DIR), $(DIRS)):
	mkdir -p $@

$(addprefix $(D_DIR), $(DIRS)):
	mkdir -p $@

.PHONY: clean
clean:
	make -C $(LIBUNIT_PATH) clean
	$(RM) $(addprefix $(O_DIR), $(O_FILES))
	$(RM) $(addprefix $(D_DIR), $(D_FILES))
	rmdir $(addprefix $(O_DIR), $(DIRS)) 2> /dev/null || true
	rmdir $(O_DIR) 2> /dev/null || true
	rmdir $(addprefix $(D_DIR), $(DIRS)) 2> /dev/null || true
	rmdir $(D_DIR) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	make -C $(LIBUNIT_PATH) fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(D_DIR)*.d)
