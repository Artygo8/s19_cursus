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

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		= ./src
SRCSC		= objects/cam.c	\
				objects/light.c \
				objects/shapes/cylinder.c \
				objects/shapes/plane.c \
				objects/shapes/sphere.c \
				objects/shapes/square.c \
				objects/shapes/triangle.c \
				utils/ato.c \
				utils/colors.c \
				utils/equation.c \
				utils/istype.c \
				utils/vector.c \
				utils/vector2.c \
				main/events.c \
				main/parse.c \
				main/main.c \
				main/materials.c \
				main/data.c \
				main/tab.c \

#	Objects
OBJDIR		= obj
OBJS		= $(SRCSC:*.c=*.o)

#	Headers
DIRH		= ./src
SRCSH		= minirt.h

#	Libraries
MINILIBDIR	= ./includes/minilibx
MINILIB		= libmlx.a
LIBFTDIR	= ./includes/libft
LIBFT		= libft.a

#	Name
NAME		= miniRT

#	Compiling Utilities
CC		= gcc
AR		= ar -rc
RM		= rm -f

#################
##    AUTO     ##
#################

OBJS	=	$(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
OS		:=	$(shell uname -s)

$(foreach S, $(SRCSC), $(eval VPATH += $(SRCDIR)/$(S)))

ifeq (${OS},Linux)
	PATHLIB		= -I /usr/include -g -lmlx -L /usr/lib
	CFLAGS		= -lXext -lX11 -lm
else
	CFLAGS		= -framework OpenGL -framework AppKit
endif

$(NAME):	${OBJS} ${MINILIB} ${LIBFT}
			${CC} ${VPATH} ${PATHLIB} ${OBJS} ${MINILIBDIR}/${MINILIB} \
			${LIBFTDIR}/${LIBFT} ${CFLAGS} -o ${NAME}

$(MINILIB):	${MINILIBDIR}
			cd ${MINILIBDIR} && make $@

$(LIBFT):	${LIBFTDIR}
			cd ${LIBFTDIR} && make bonus

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ${MINILIBDIR} && make $@
			cd ${LIBFTDIR} && make $@

fclean:		clean
			${RM} ${NAME}
			cd ${LIBFTDIR} && make $@

re:			fclean all

bonus:		all

test:		re
			./miniRT scenes/simple/sphere.rt
tr:			re
			./miniRT scenes/simple/triangle.rt
cy:			re
			./miniRT scenes/simple/cylinder.rt
sq:			re
			./miniRT scenes/simple/square.rt
sp:			re
			./miniRT scenes/simple/sphere.rt

.PHONY:		all clean fclean re
