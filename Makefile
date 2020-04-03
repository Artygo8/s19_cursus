SRC_NAMES	=	ms_prompt.c \
				minishell.c \
				get_next_entry.c \
				get_next_line.c \
				ms_get.c \
				cmd_struct.c

SRC		=	$(addprefix srcs/, $(SRC_NAMES))
OBJ		= $(SRC:%.c=%.o)

NAME	=	minishell

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar -rc

all:		$(NAME)

$(NAME):	$(OBJ) libftprintf.a
			$(CC) -o $(NAME) $(OBJ) libs/ft_printf/libftprintf.a

test:		all
			./minishell
clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

libftprintf.a:
			cd libs/ft_printf/ && make
