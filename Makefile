# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 15:08:48 by agossuin          #+#    #+#              #
#    Updated: 2019/11/27 15:08:51 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= objects/cam.c	\
				objects/cylinder.c \
				objects/light.c \
				objects/plane.c \
				objects/sphere.c \
				objects/square.c \
				objects/triangle.c \
				utils/ato.c \
				utils/colors.c \
				utils/colors2.c \
				utils/equation.c \
				utils/vector.c \
				utils/vector2.c \
				init.c \
				minirt.c \
				tab.c \
				get_next_line/*.c \
				libft/*.c

SRCSH		= minirt.h

OBJS		= $(SRCSC:*.c=*.o)

MINILIBDIR	= minilib

MINILIB		= minilibx/libmlx.a

NAME		= miniRT

CC		= gcc

AR		= ar -rc

RM		= rm -f

OS		:= $(shell uname -s)

ifeq (${OS},Linux)
	PATHLIB		= -I /usr/include -g -lmlx -L /usr/lib
	CFLAGS		= -lXext -lX11 -lm
else
	PATHLIB	=
	CFLAGS		= -framework OpenGL -framework AppKit
endif

$(NAME):
			gcc ${SRCSC} ${PATHLIB} ${MINILIB} ${CFLAGS}

all:		${NAME}

clean:

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		all

test:		make
			./a.out scenes/simple/sphere.rt

tr:
			./a.out scenes/simple/triangle.rt

cy:
			./a.out scenes/simple/cylinder.rt

sq:
			./a.out scenes/simple/square.rt

sp:
			./a.out scenes/simple/sphere.rt

.PHONY:		all clean fclean re
