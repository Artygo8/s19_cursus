# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/09 17:27:22 by agossuin          #+#    #+#              #
#    Updated: 2020/10/07 18:59:13 by pmaldagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAMES	=	main.c \
				parser.c \
				pipeline.c \
				prompt.c \
				\
				builtins/cd.c \
				builtins/env.c \
				builtins/pwd.c \
				builtins/echo.c \
				builtins/exec.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/unset.c \
				\
				data/child.c\
				data/errors.c\
				data/msh.c\
				data/signal.c\
				data/status.c\
				\
				format/lexer.c \
				format/clean.c \
				format/get_cmd.c \
				format/get_var.c \
				format/get_redir.c \
				format/translate.c \
				\
				utils/files.c \
				utils/alloc_secure.c \
				utils/write_secure.c \
				utils/lists.c \
				utils/numbers.c \
				utils/strings.c

SRC			=	$(addprefix src/, $(SRC_NAMES))
OBJ			=	$(SRC:%.c=%.o)

NAME		=	minishell
UNAME_S		:= $(shell uname -s)
LIBFT		=	tools/libft/libft.a


ifeq ($(UNAME_S), Darwin)
	LFT		=	$(LIBFT)
endif
ifeq ($(UNAME_S), Linux)
	LFT		=	-L./tools/libft -lft
endif

CC			=	gcc -g -Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar -rc

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT)

clean:
			cd tools/libft/ && make $@
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(LIBFT)
			$(RM) $(NAME)

re:			fclean all

$(LIBFT):
			make bonus -C ./tools/libft

.PHONY: all clean fclean re