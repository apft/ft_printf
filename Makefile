# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:28:44 by apion             #+#    #+#              #
#    Updated: 2019/03/01 19:34:02 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:= /bin/sh
RM			:= /bin/rm -f
CC			:= gcc
ifndef NOERR
CFLAGS		:= -Wall -Wextra -Werror
endif
CINCLUDES	= $(addprefix -I, $(H_DIR))
CPPFLAGS	= -MMD -MP -MF $(D_DIR)/$*.d

NAME		:= libftprintf.a
C_DIR		:= srcs
H_DIR		:= incs
O_DIR		:= .obj
D_DIR		:= $(O_DIR)
C_FILES		:= srcs/extract_arg.c \
				srcs/extractor.c \
				srcs/filler.c \
				srcs/filler_float.c \
				srcs/filter.c \
				srcs/float_round.c \
				srcs/ft_printf.c \
				srcs/ft_vprintf.c \
				srcs/wrapper.c \
				srcs/parser.c \
				srcs/utils.c \
				srcs/utils_float.c \
				srcs/handlers/handle_char_conv.c \
				srcs/handlers/handle_float_conv.c \
				srcs/handlers/handle_float_conv_hex.c \
				srcs/handlers/handle_int_conv.c \
				srcs/handlers/handle_int_conv_char.c \
				srcs/handlers/handle_int_conv_int.c \
				srcs/handlers/handle_int_conv_long.c \
				srcs/handlers/handle_int_conv_long_long.c \
				srcs/handlers/handle_int_conv_short.c \
				srcs/handlers/handle_int_conv_uchar.c \
				srcs/handlers/handle_int_conv_uint.c \
				srcs/handlers/handle_int_conv_ulong.c \
				srcs/handlers/handle_int_conv_ulong_long.c \
				srcs/handlers/handle_int_conv_ushort.c \
				srcs/handlers/handle_str_conv.c \
				srcs/bigint/add.c \
				srcs/bigint/cmp.c \
				srcs/bigint/init.c \
				srcs/bigint/shift.c \
				srcs/bigint/sub.c \
				srcs/bigint/utils.c
O_FILES		:= $(C_FILES:%.c=%.o)
D_FILES		:= $(C_FILES:%.c=%.d)

TEST_LIBUNIT	:= test/test_printf

TEST_DIR		:= test/old
TEST_BIN		:= test/.bin
TEST_INT		:= test_int
TEST_INT_BIN	:= $(TEST_INT).bin
MAIN_INT		:= $(TEST_DIR)/main_int.c

TEST_FLOAT		:= test_float
TEST_FLOAT_BIN	:= $(TEST_FLOAT).bin
MAIN_FLOAT		:= $(TEST_DIR)/main_float.c

TEST_BEHAVIOUR		:= test_behaviour
TEST_BEHAVIOUR_BIN	:= $(TEST_BEHAVIOUR).bin
MAIN_BEHAVIOUR		:= $(TEST_DIR)/float_behaviour.c

.PHONY: all
all: $(NAME)

$(NAME): $(addprefix $(O_DIR)/, $(O_FILES))
	$(AR) rs $@ $?

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(D_DIR)/%.d | $(O_DIR)/$(C_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -o $@ -c $<

$(O_DIR)/$(C_DIR):
	mkdir -p $@

%.d: ;
.PRECIOUS: %.d

.PHONY: clean
clean:
	$(RM) $(addprefix $(O_DIR)/, $(O_FILES))
	$(RM) $(addprefix $(O_DIR)/, $(D_FILES))
	rmdir -p $(O_DIR)/$(C_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(D_DIR)/*.d)

# --- Tests --- #

.PHONY: test
test:
	$(MAKE) -C $(TEST_LIBUNIT) $@

$(TEST_INT_BIN): $(NAME) $(MAIN_INT)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $(TEST_BIN)/$@

$(TEST_INT): $(TEST_INT_BIN)
	./$(TEST_BIN)/$^

$(TEST_FLOAT_BIN): $(NAME) $(MAIN_FLOAT)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $(TEST_BIN)/$@

$(TEST_FLOAT): $(TEST_FLOAT_BIN)
	./$(TEST_BIN)/$^

$(TEST_BEHAVIOUR_BIN): $(NAME) $(MAIN_BEHAVIOUR)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $(TEST_BIN)/$@

$(TEST_BEHAVIOUR): $(TEST_BEHAVIOUR_BIN)
	./$(TEST_BIN)/$^
