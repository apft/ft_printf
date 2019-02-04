# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2018/12/02 18:37:11 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/sh
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -I$(H_DIR)
CPPFLAGS	= -MMD -MP -MF $(D_DIR)/$*.d
AR			= ar -rcs

NAME		= libunit.a
C_DIR		=
H_DIR		= libft/includes
D_DIR		= .dep
O_DIR		= .obj
C_FILES		:= worker.c unit_test.c utils.c
O_FILES		:= $(C_FILES:%.c=%.o)
D_FILES		:= $(C_FILES:%.c=%.d)

.PHONY: all
all: $(NAME)

$(NAME): $(addprefix $(O_DIR)/,$(O_FILES))
	$(AR) $@ $?

%.o: %.c
$(O_DIR)/%.o: %.c $(D_DIR)/%.d | $(D_DIR) $(O_DIR)
	$(CC) $(CFLAGS) $(CINCLUDES) $(CPPFLAGS) -o $@ -c $<

$(D_DIR)/%.d: ;
.PRECIOUS: $(D_DIR)/%.d

$(D_DIR):
	mkdir $@

$(O_DIR):
	mkdir $@

.PHONY: clean
clean:
	$(RM) $(addprefix $(O_DIR)/,$(O_FILES))
	$(RM) $(addprefix $(D_DIR)/,$(D_FILES))
	rmdir $(O_DIR) 2> /dev/null || true
	rmdir $(D_DIR) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(D_DIR)/*.d)
