# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2019/03/22 19:16:40 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPRINTF_PATH	:= ../..
FTPRINTF_LIB	:= $(FTPRINTF_PATH)/libftprintf.a

MAKEFILES_PATH	:= makefiles
include $(wildcard $(MAKEFILES_PATH)/*.mk)


SHELL			:= /bin/sh
RM				:= /bin/rm -f
MAKE			:= make
CC				:= gcc
ifndef NOERR
CFLAGS			:= -Wall -Wextra -Werror
endif
CINCLUDES		= $(addprefix -I,$(H_DIR))
CPPFLAGS		= -MMD -MP -MF $(O_DIR)/$*.d

LIBUNIT_NAME	= libunit.a
LIBUNIT_PATH	= ../framework
LIBUNIT			= $(LIBUNIT_PATH)/$(LIBUNIT_NAME)

NAME			= $(EXEC).out
EXEC			= test
C_DIR			=
H_DIR			= . $(LIBUNIT_PATH) $(FTPRINTF_PATH)/incs
O_DIR			= .obj
C_FILES			:= main.c \
					utils.c \
					print_bigint.c
C_FILES			+=	$(C_FILES_INT)
C_FILES			+=	$(C_FILES_STR_CHAR) $(C_FILES_PTR_PERCENT)
C_FILES			+=	test_float/00_launcher.c
C_FILES			+= 	$(C_FILES_FLOAT) $(C_FILES_FLOAT_HEXA) \
					$(C_FILES_FLOAT_SUBNORMAL) $(C_FILES_FLOAT_LIMITS)
C_FILES			+= 	$(C_FILES_FLOAT_LONG_DBL) \
					$(C_FILES_FLOAT_LONG_DBL_SUBNORMAL) \
					$(C_FILES_FLOAT_LONG_DBL_LIMITS)
C_FILES			+=	$(C_FILES_BIGINT)
O_FILES			:= $(C_FILES:%.c=%.o)
D_FILES			:= $(C_FILES:%.c=%.d)
O_TREE			= $(shell find $(O_DIR) -type d -print 2> /dev/null | tail -r)

.SUFFIXES:
.SUFFIXES: .c .o .d

.SECONDEXPANSION:

.PHONY: all
all: $(NAME)

.PHONY: lib
lib: $(FTPRINTF_LIB) $(LIBUNIT)

$(FTPRINTF_LIB): .FORCE
	make -C $(FTPRINTF_PATH)

$(LIBUNIT): .FORCE
	make -C $(LIBUNIT_PATH)

$(NAME): $(addprefix $(O_DIR)/, $(O_FILES)) $(LIBUNIT) $(FTPRINTF_LIB)
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^

.PHONY: $(EXEC)
$(EXEC): all
	clear
	@./$(NAME) || true

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(O_DIR)/%.d | $$(@D)/.
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CINCLUDES) $(CPPFLAGS) -o $@ -c $<

.PRECIOUS: $(O_DIR)/. $(O_DIR)%/.
$(O_DIR)/. $(O_DIR)%/.:
	mkdir -p $@

.PRECIOUS: $(O_DIR)/%.d
$(O_DIR)/%.d: ;

.PHONY: clean
clean:
	make -C $(LIBUNIT_PATH) clean
	$(RM) $(addprefix $(O_DIR)/, $(O_FILES))
	$(RM) $(addprefix $(O_DIR)/, $(D_FILES))
	echo $(O_TREE) | xargs rmdir 2> /dev/null || true
	rmdir $(O_DIR) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	make -C $(LIBUNIT_PATH) fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.FORCE:

-include $(addprefix $(O_DIR)/, $(D_FILES))
