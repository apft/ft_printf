# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_float                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 14:36:04 by apion             #+#    #+#              #
#    Updated: 2019/03/13 17:07:07 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES_FLOAT	:= test_float/00_launcher.c \
	test_float/001_test_float_null_f_0_0.c \
	test_float/002_test_float_null_neg_f_0_0.c \
	test_float/003_test_float_pos_one_f_0_0.c \
	test_float/004_test_float_pos_two_f_0_0.c \
	test_float/005_test_float_pos_big_f_0_0.c \
	test_float/006_test_float_pos_small_f_0_0.c \
	test_float/007_test_float_pos_very_small_f_0_0.c \
	test_float/008_test_float_neg_f_0_0.c \
	test_float/009_test_float_inf_one_f_0_0.c \
	test_float/010_test_float_inf_zero_one_f_0_0.c \
	test_float/011_test_float_den_f_0_0.c \
	test_float/012_test_float_round_even_top_f_0_0.c \
	test_float/013_test_float_round_even_down_f_0_0.c \
	test_float/014_test_float_round_even_top_neg_f_0_0.c \
	test_float/015_test_float_round_even_down_neg_f_0_0.c \
	test_float/016_test_float_dbl_max_f_0_0.c \
	test_float/017_test_float_dbl_min_f_0_0.c \
	test_float/018_test_float_null_f_1_1.c \
	test_float/019_test_float_null_neg_f_1_1.c \
	test_float/020_test_float_pos_one_f_1_1.c \
	test_float/021_test_float_pos_two_f_1_1.c \
	test_float/022_test_float_pos_big_f_1_1.c \
	test_float/023_test_float_pos_small_f_1_1.c \
	test_float/024_test_float_pos_very_small_f_1_1.c \
	test_float/025_test_float_neg_f_1_1.c \
	test_float/026_test_float_inf_one_f_1_1.c \
	test_float/027_test_float_inf_zero_one_f_1_1.c \
	test_float/028_test_float_den_f_1_1.c \
	test_float/029_test_float_round_even_top_f_1_1.c \
	test_float/030_test_float_round_even_down_f_1_1.c \
	test_float/031_test_float_round_even_top_neg_f_1_1.c \
	test_float/032_test_float_round_even_down_neg_f_1_1.c \
	test_float/033_test_float_dbl_max_f_1_1.c \
	test_float/034_test_float_dbl_min_f_1_1.c \
	test_float/035_test_float_null_f_2_2.c \
	test_float/036_test_float_null_neg_f_2_2.c \
	test_float/037_test_float_pos_one_f_2_2.c \
	test_float/038_test_float_pos_two_f_2_2.c \
	test_float/039_test_float_pos_big_f_2_2.c \
	test_float/040_test_float_pos_small_f_2_2.c \
	test_float/041_test_float_pos_very_small_f_2_2.c \
	test_float/042_test_float_neg_f_2_2.c \
	test_float/043_test_float_inf_one_f_2_2.c \
	test_float/044_test_float_inf_zero_one_f_2_2.c \
	test_float/045_test_float_den_f_2_2.c \
	test_float/046_test_float_round_even_top_f_2_2.c \
	test_float/047_test_float_round_even_down_f_2_2.c \
	test_float/048_test_float_round_even_top_neg_f_2_2.c \
	test_float/049_test_float_round_even_down_neg_f_2_2.c \
	test_float/050_test_float_dbl_max_f_2_2.c \
	test_float/051_test_float_dbl_min_f_2_2.c \
	test_float/052_test_float_null_f_3_3.c \
	test_float/053_test_float_null_neg_f_3_3.c \
	test_float/054_test_float_pos_one_f_3_3.c \
	test_float/055_test_float_pos_two_f_3_3.c \
	test_float/056_test_float_pos_big_f_3_3.c \
	test_float/057_test_float_pos_small_f_3_3.c \
	test_float/058_test_float_pos_very_small_f_3_3.c \
	test_float/059_test_float_neg_f_3_3.c \
	test_float/060_test_float_inf_one_f_3_3.c \
	test_float/061_test_float_inf_zero_one_f_3_3.c \
	test_float/062_test_float_den_f_3_3.c \
	test_float/063_test_float_round_even_top_f_3_3.c \
	test_float/064_test_float_round_even_down_f_3_3.c \
	test_float/065_test_float_round_even_top_neg_f_3_3.c \
	test_float/066_test_float_round_even_down_neg_f_3_3.c \
	test_float/067_test_float_dbl_max_f_3_3.c \
	test_float/068_test_float_dbl_min_f_3_3.c \
	test_float/069_test_float_null_f_4_4.c \
	test_float/070_test_float_null_neg_f_4_4.c \
	test_float/071_test_float_pos_one_f_4_4.c \
	test_float/072_test_float_pos_two_f_4_4.c \
	test_float/073_test_float_pos_big_f_4_4.c \
	test_float/074_test_float_pos_small_f_4_4.c \
	test_float/075_test_float_pos_very_small_f_4_4.c \
	test_float/076_test_float_neg_f_4_4.c \
	test_float/077_test_float_inf_one_f_4_4.c \
	test_float/078_test_float_inf_zero_one_f_4_4.c \
	test_float/079_test_float_den_f_4_4.c \
	test_float/080_test_float_round_even_top_f_4_4.c \
	test_float/081_test_float_round_even_down_f_4_4.c \
	test_float/082_test_float_round_even_top_neg_f_4_4.c \
	test_float/083_test_float_round_even_down_neg_f_4_4.c \
	test_float/084_test_float_dbl_max_f_4_4.c \
	test_float/085_test_float_dbl_min_f_4_4.c \
	test_float/086_test_float_null_f_5_5.c \
	test_float/087_test_float_null_neg_f_5_5.c \
	test_float/088_test_float_pos_one_f_5_5.c \
	test_float/089_test_float_pos_two_f_5_5.c \
	test_float/090_test_float_pos_big_f_5_5.c \
	test_float/091_test_float_pos_small_f_5_5.c \
	test_float/092_test_float_pos_very_small_f_5_5.c \
	test_float/093_test_float_neg_f_5_5.c \
	test_float/094_test_float_inf_one_f_5_5.c \
	test_float/095_test_float_inf_zero_one_f_5_5.c \
	test_float/096_test_float_den_f_5_5.c \
	test_float/097_test_float_round_even_top_f_5_5.c \
	test_float/098_test_float_round_even_down_f_5_5.c \
	test_float/099_test_float_round_even_top_neg_f_5_5.c \
	test_float/100_test_float_round_even_down_neg_f_5_5.c \
	test_float/101_test_float_dbl_max_f_5_5.c \
	test_float/102_test_float_dbl_min_f_5_5.c \
	test_float/103_test_float_null_f_6_6.c \
	test_float/104_test_float_null_neg_f_6_6.c \
	test_float/105_test_float_pos_one_f_6_6.c \
	test_float/106_test_float_pos_two_f_6_6.c \
	test_float/107_test_float_pos_big_f_6_6.c \
	test_float/108_test_float_pos_small_f_6_6.c \
	test_float/109_test_float_pos_very_small_f_6_6.c \
	test_float/110_test_float_neg_f_6_6.c \
	test_float/111_test_float_inf_one_f_6_6.c \
	test_float/112_test_float_inf_zero_one_f_6_6.c \
	test_float/113_test_float_den_f_6_6.c \
	test_float/114_test_float_round_even_top_f_6_6.c \
	test_float/115_test_float_round_even_down_f_6_6.c \
	test_float/116_test_float_round_even_top_neg_f_6_6.c \
	test_float/117_test_float_round_even_down_neg_f_6_6.c \
	test_float/118_test_float_dbl_max_f_6_6.c \
	test_float/119_test_float_dbl_min_f_6_6.c \
	test_float/120_test_float_null_f_7_7.c \
	test_float/121_test_float_null_neg_f_7_7.c \
	test_float/122_test_float_pos_one_f_7_7.c \
	test_float/123_test_float_pos_two_f_7_7.c \
	test_float/124_test_float_pos_big_f_7_7.c \
	test_float/125_test_float_pos_small_f_7_7.c \
	test_float/126_test_float_pos_very_small_f_7_7.c \
	test_float/127_test_float_neg_f_7_7.c \
	test_float/128_test_float_inf_one_f_7_7.c \
	test_float/129_test_float_inf_zero_one_f_7_7.c \
	test_float/130_test_float_den_f_7_7.c \
	test_float/131_test_float_round_even_top_f_7_7.c \
	test_float/132_test_float_round_even_down_f_7_7.c \
	test_float/133_test_float_round_even_top_neg_f_7_7.c \
	test_float/134_test_float_round_even_down_neg_f_7_7.c \
	test_float/135_test_float_dbl_max_f_7_7.c \
	test_float/136_test_float_dbl_min_f_7_7.c \
	test_float/137_test_float_null_f_8_8.c \
	test_float/138_test_float_null_neg_f_8_8.c \
	test_float/139_test_float_pos_one_f_8_8.c \
	test_float/140_test_float_pos_two_f_8_8.c \
	test_float/141_test_float_pos_big_f_8_8.c \
	test_float/142_test_float_pos_small_f_8_8.c \
	test_float/143_test_float_pos_very_small_f_8_8.c \
	test_float/144_test_float_neg_f_8_8.c \
	test_float/145_test_float_inf_one_f_8_8.c \
	test_float/146_test_float_inf_zero_one_f_8_8.c \
	test_float/147_test_float_den_f_8_8.c \
	test_float/148_test_float_round_even_top_f_8_8.c \
	test_float/149_test_float_round_even_down_f_8_8.c \
	test_float/150_test_float_round_even_top_neg_f_8_8.c \
	test_float/151_test_float_round_even_down_neg_f_8_8.c \
	test_float/152_test_float_dbl_max_f_8_8.c \
	test_float/153_test_float_dbl_min_f_8_8.c \
	test_float/154_test_float_null_f_9_9.c \
	test_float/155_test_float_null_neg_f_9_9.c \
	test_float/156_test_float_pos_one_f_9_9.c \
	test_float/157_test_float_pos_two_f_9_9.c \
	test_float/158_test_float_pos_big_f_9_9.c \
	test_float/159_test_float_pos_small_f_9_9.c \
	test_float/160_test_float_pos_very_small_f_9_9.c \
	test_float/161_test_float_neg_f_9_9.c \
	test_float/162_test_float_inf_one_f_9_9.c \
	test_float/163_test_float_inf_zero_one_f_9_9.c \
	test_float/164_test_float_den_f_9_9.c \
	test_float/165_test_float_round_even_top_f_9_9.c \
	test_float/166_test_float_round_even_down_f_9_9.c \
	test_float/167_test_float_round_even_top_neg_f_9_9.c \
	test_float/168_test_float_round_even_down_neg_f_9_9.c \
	test_float/169_test_float_dbl_max_f_9_9.c \
	test_float/170_test_float_dbl_min_f_9_9.c \
	test_float/171_test_float_null_f_10_10.c \
	test_float/172_test_float_null_neg_f_10_10.c \
	test_float/173_test_float_pos_one_f_10_10.c \
	test_float/174_test_float_pos_two_f_10_10.c \
	test_float/175_test_float_pos_big_f_10_10.c \
	test_float/176_test_float_pos_small_f_10_10.c \
	test_float/177_test_float_pos_very_small_f_10_10.c \
	test_float/178_test_float_neg_f_10_10.c \
	test_float/179_test_float_inf_one_f_10_10.c \
	test_float/180_test_float_inf_zero_one_f_10_10.c \
	test_float/181_test_float_den_f_10_10.c \
	test_float/182_test_float_round_even_top_f_10_10.c \
	test_float/183_test_float_round_even_down_f_10_10.c \
	test_float/184_test_float_round_even_top_neg_f_10_10.c \
	test_float/185_test_float_round_even_down_neg_f_10_10.c \
	test_float/186_test_float_dbl_max_f_10_10.c \
	test_float/187_test_float_dbl_min_f_10_10.c \
	test_float/188_test_float_null_f_11_11.c \
	test_float/189_test_float_null_neg_f_11_11.c \
	test_float/190_test_float_pos_one_f_11_11.c \
	test_float/191_test_float_pos_two_f_11_11.c \
	test_float/192_test_float_pos_big_f_11_11.c \
	test_float/193_test_float_pos_small_f_11_11.c \
	test_float/194_test_float_pos_very_small_f_11_11.c \
	test_float/195_test_float_neg_f_11_11.c \
	test_float/196_test_float_inf_one_f_11_11.c \
	test_float/197_test_float_inf_zero_one_f_11_11.c \
	test_float/198_test_float_den_f_11_11.c \
	test_float/199_test_float_round_even_top_f_11_11.c \
	test_float/200_test_float_round_even_down_f_11_11.c \
	test_float/201_test_float_round_even_top_neg_f_11_11.c \
	test_float/202_test_float_round_even_down_neg_f_11_11.c \
	test_float/203_test_float_dbl_max_f_11_11.c \
	test_float/204_test_float_dbl_min_f_11_11.c \
	test_float/205_test_float_null_f_12_12.c \
	test_float/206_test_float_null_neg_f_12_12.c \
	test_float/207_test_float_pos_one_f_12_12.c \
	test_float/208_test_float_pos_two_f_12_12.c \
	test_float/209_test_float_pos_big_f_12_12.c \
	test_float/210_test_float_pos_small_f_12_12.c \
	test_float/211_test_float_pos_very_small_f_12_12.c \
	test_float/212_test_float_neg_f_12_12.c \
	test_float/213_test_float_inf_one_f_12_12.c \
	test_float/214_test_float_inf_zero_one_f_12_12.c \
	test_float/215_test_float_den_f_12_12.c \
	test_float/216_test_float_round_even_top_f_12_12.c \
	test_float/217_test_float_round_even_down_f_12_12.c \
	test_float/218_test_float_round_even_top_neg_f_12_12.c \
	test_float/219_test_float_round_even_down_neg_f_12_12.c \
	test_float/220_test_float_dbl_max_f_12_12.c \
	test_float/221_test_float_dbl_min_f_12_12.c \
	test_float/222_test_float_null_f_13_13.c \
	test_float/223_test_float_null_neg_f_13_13.c \
	test_float/224_test_float_pos_one_f_13_13.c \
	test_float/225_test_float_pos_two_f_13_13.c \
	test_float/226_test_float_pos_big_f_13_13.c \
	test_float/227_test_float_pos_small_f_13_13.c \
	test_float/228_test_float_pos_very_small_f_13_13.c \
	test_float/229_test_float_neg_f_13_13.c \
	test_float/230_test_float_inf_one_f_13_13.c \
	test_float/231_test_float_inf_zero_one_f_13_13.c \
	test_float/232_test_float_den_f_13_13.c \
	test_float/233_test_float_round_even_top_f_13_13.c \
	test_float/234_test_float_round_even_down_f_13_13.c \
	test_float/235_test_float_round_even_top_neg_f_13_13.c \
	test_float/236_test_float_round_even_down_neg_f_13_13.c \
	test_float/237_test_float_dbl_max_f_13_13.c \
	test_float/238_test_float_dbl_min_f_13_13.c \
	test_float/239_test_float_null_f_14_14.c \
	test_float/240_test_float_null_neg_f_14_14.c \
	test_float/241_test_float_pos_one_f_14_14.c \
	test_float/242_test_float_pos_two_f_14_14.c \
	test_float/243_test_float_pos_big_f_14_14.c \
	test_float/244_test_float_pos_small_f_14_14.c \
	test_float/245_test_float_pos_very_small_f_14_14.c \
	test_float/246_test_float_neg_f_14_14.c \
	test_float/247_test_float_inf_one_f_14_14.c \
	test_float/248_test_float_inf_zero_one_f_14_14.c \
	test_float/249_test_float_den_f_14_14.c \
	test_float/250_test_float_round_even_top_f_14_14.c \
	test_float/251_test_float_round_even_down_f_14_14.c \
	test_float/252_test_float_round_even_top_neg_f_14_14.c \
	test_float/253_test_float_round_even_down_neg_f_14_14.c \
	test_float/254_test_float_dbl_max_f_14_14.c \
	test_float/255_test_float_dbl_min_f_14_14.c \
	test_float/256_test_float_null_f_15_15.c \
	test_float/257_test_float_null_neg_f_15_15.c \
	test_float/258_test_float_pos_one_f_15_15.c \
	test_float/259_test_float_pos_two_f_15_15.c \
	test_float/260_test_float_pos_big_f_15_15.c \
	test_float/261_test_float_pos_small_f_15_15.c \
	test_float/262_test_float_pos_very_small_f_15_15.c \
	test_float/263_test_float_neg_f_15_15.c \
	test_float/264_test_float_inf_one_f_15_15.c \
	test_float/265_test_float_inf_zero_one_f_15_15.c \
	test_float/266_test_float_den_f_15_15.c \
	test_float/267_test_float_round_even_top_f_15_15.c \
	test_float/268_test_float_round_even_down_f_15_15.c \
	test_float/269_test_float_round_even_top_neg_f_15_15.c \
	test_float/270_test_float_round_even_down_neg_f_15_15.c \
	test_float/271_test_float_dbl_max_f_15_15.c \
	test_float/272_test_float_dbl_min_f_15_15.c \
	test_float/273_test_float_null_f_16_16.c \
	test_float/274_test_float_null_neg_f_16_16.c \
	test_float/275_test_float_pos_one_f_16_16.c \
	test_float/276_test_float_pos_two_f_16_16.c \
	test_float/277_test_float_pos_big_f_16_16.c \
	test_float/278_test_float_pos_small_f_16_16.c \
	test_float/279_test_float_pos_very_small_f_16_16.c \
	test_float/280_test_float_neg_f_16_16.c \
	test_float/281_test_float_inf_one_f_16_16.c \
	test_float/282_test_float_inf_zero_one_f_16_16.c \
	test_float/283_test_float_den_f_16_16.c \
	test_float/284_test_float_round_even_top_f_16_16.c \
	test_float/285_test_float_round_even_down_f_16_16.c \
	test_float/286_test_float_round_even_top_neg_f_16_16.c \
	test_float/287_test_float_round_even_down_neg_f_16_16.c \
	test_float/288_test_float_dbl_max_f_16_16.c \
	test_float/289_test_float_dbl_min_f_16_16.c \
	test_float/290_test_float_null_f_17_17.c \
	test_float/291_test_float_null_neg_f_17_17.c \
	test_float/292_test_float_pos_one_f_17_17.c \
	test_float/293_test_float_pos_two_f_17_17.c \
	test_float/294_test_float_pos_big_f_17_17.c \
	test_float/295_test_float_pos_small_f_17_17.c \
	test_float/296_test_float_pos_very_small_f_17_17.c \
	test_float/297_test_float_neg_f_17_17.c \
	test_float/298_test_float_inf_one_f_17_17.c \
	test_float/299_test_float_inf_zero_one_f_17_17.c \
	test_float/300_test_float_den_f_17_17.c \
	test_float/301_test_float_round_even_top_f_17_17.c \
	test_float/302_test_float_round_even_down_f_17_17.c \
	test_float/303_test_float_round_even_top_neg_f_17_17.c \
	test_float/304_test_float_round_even_down_neg_f_17_17.c \
	test_float/305_test_float_dbl_max_f_17_17.c \
	test_float/306_test_float_dbl_min_f_17_17.c
