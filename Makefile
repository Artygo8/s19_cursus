# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 15:08:48 by agossuin          #+#    #+#              #
#    Updated: 2020/01/29 12:50:58 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		= ./src
SRCSC		= objects/cam.c	\
				objects/light.c \
				objects/mirror.c \
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
				main/bmp.c \
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
BMPS		= bmps

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
	CFLAGS		= -framework OpenGL -framework AppKit -Wall -Wextra -Werror
endif

$(NAME):	${OBJS} ${LIBFT} ${MINILIB} ${BMPS}
			@echo "miniRT - compiling"
			@${CC} ${CFLAGS} ${VPATH} ${PATHLIB} ${OBJS} ${MINILIBDIR}/${MINILIB} \
			${LIBFTDIR}/${LIBFT} ${CFLAGS} -o ${NAME}
			@echo "done."

$(LIBFT):	${LIBFTDIR}
			@cd ${LIBFTDIR} && make bonus

$(MINILIB):	${MINILIBDIR}
			@cd ${MINILIBDIR} && make $@

$(BMPS):
			@mkdir -p bmps

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ${LIBFTDIR} && make $@
			cd ${MINILIBDIR} && make $@

fclean:		clean
			@echo "miniRT - fclean"
			@${RM} ${NAME}
			@echo "done."
			@echo "libft - fclean"
			@cd ${LIBFTDIR} && make $@
			@echo "done."
			@echo "bmp - removal"
			@rm -rf ${BMPS}
			@echo "done."

re:			fclean all

.PHONY:		all clean fclean re
