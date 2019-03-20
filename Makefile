# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:28:44 by apion             #+#    #+#              #
#    Updated: 2019/03/20 20:49:57 by apion            ###   ########.fr        #
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
H_DIR		:= incs srcs/bigint
O_DIR		:= .obj
D_DIR		:= $(O_DIR)
C_FILES		:= srcs/extract_arg.c \
				srcs/extractor.c \
				srcs/filler.c \
				srcs/filler_utils.c \
				srcs/filter.c \
				srcs/ft_printf.c \
				srcs/ft_vprintf.c \
				srcs/wrapper.c \
				srcs/parser.c \
				srcs/utils.c \
				srcs/float_bigint.c \
				srcs/float_filler.c \
				srcs/float_round.c \
				srcs/float_utils.c \
				srcs/float_hexa.c \
				srcs/handlers/handle_char_conv.c \
				srcs/handlers/handle_float_conv.c \
				srcs/handlers/handle_float_conv_hex.c \
				srcs/handlers/handle_float_limit.c \
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
				srcs/bigint/copy.c \
				srcs/bigint/init.c \
				srcs/bigint/mult.c \
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

.SECONDEXPANSION:

.PHONY: all
all: $(NAME)

$(NAME): $(addprefix $(O_DIR)/, $(O_FILES))
	$(AR) rs $@ $?

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(D_DIR)/%.d | $$(@D)/.
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -o $@ -c $<

.PRECIOUS: $(O_DIR)/. $(O_DIR)%/.
$(O_DIR)/. $(O_DIR)%/.:
	mkdir -p $@

.PRECIOUS: %.d
%.d: ;

.PHONY: clean
clean:
	$(RM) $(addprefix $(O_DIR)/, $(O_FILES))
	$(RM) $(addprefix $(D_DIR)/, $(D_FILES))
	rmdir $$(ls -R -1 $(O_DIR) | grep -A1 "^$$" | grep -v -E "(^$$|^--$$)" | tr -d ':' | sort -r) 2> /dev/null || true
	rmdir $$(ls -R -1 $(D_DIR) | grep -A1 "^$$" | grep -v -E "(^$$|^--$$)" | tr -d ':' | sort -r) 2> /dev/null || true
	rmdir $(O_DIR) 2> /dev/null || true
	rmdir $(D_DIR) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

-include $(D_FILES)

# --- Tests --- #

.PHONY: lib
lib:
	$(MAKE)
	$(MAKE) -C $(TEST_LIBUNIT)

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
