# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2019/02/04 18:05:46 by apion            ###   ########.fr        #
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
						test_int/00_launcher.c \
						test_int/01_test_int_neg.c \
						test_int/02_test_int_null.c \
						test_int/03_test_int_pos.c \
						test_int/04_test_int_neg2.c \
						test_int/05_test_int_min.c \
						test_int/06_test_int_max.c \
						test_int/07_test_long_min.c \
						test_int/08_test_long_max.c \
						test_int/09_test_long_long_min.c \
						test_int/10_test_long_long_max.c \
						test_int/11_test_long_long.c \
						test_int/12_test_int_neg_i.c \
						test_int/13_test_int_null_i.c \
						test_int/14_test_int_pos_i.c \
						test_int/15_test_int_neg2_i.c \
						test_int/16_test_int_min_i.c \
						test_int/17_test_int_max_i.c \
						test_int/18_test_long_min_i.c \
						test_int/19_test_long_max_i.c \
						test_int/20_test_long_long_min_i.c \
						test_int/21_test_long_long_max_i.c \
						test_int/22_test_long_long_i.c
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
