# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2019/03/12 17:07:10 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPRINTF_PATH		:= ../../
FTPRINTF_LIB		:= $(FTPRINTF_PATH)libftprintf.a

MAKEFILES_PATH		:= makefiles
include $(wildcard $(MAKEFILES_PATH)/*.mk)

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
H_DIR				= . $(LIBUNIT_PATH) $(FTPRINTF_PATH)srcs/bigint
D_DIR				= .dep/
O_DIR				= .obj/
C_FILES				:= main.c \
						utils.c \
						print_bigint.c
C_FILES				+=	$(C_FILES_INT) $(C_FILES_FLOAT_HEXA) $(C_FILES_FLOAT) \
						$(C_FILES_STR_CHAR) $(C_FILES_PTR_PERCENT) \
						$(C_FILES_BIGINT)
O_FILES			:= $(C_FILES:%.c=%.o)
D_FILES			:= $(C_FILES:%.c=%.d)
DIRS			:= $(strip $(filter-out ./,$(sort $(dir $(C_FILES))))) .

.SUFFIXES:
.SUFFIXES: .c .o .d

.PHONY: all
all: $(NAME)

.PHONY: lib
lib:
	make -C $(FTPRINTF_PATH)
	make -C $(LIBUNIT_PATH)

$(FTPRINTF_LIB):
	make -C $(FTPRINTF_PATH)

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
