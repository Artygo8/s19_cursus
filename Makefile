# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 15:08:48 by agossuin          #+#    #+#              #
#    Updated: 2020/05/25 13:22:51 by agossuin         ###   ########.fr        #
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
	MINILIBDIR	= ./includes/minilibx_linux
	CFLAGS		= -lXext -lX11 -lm
endif
ifeq (${OS},Darwin)
	CFLAGS		= -framework OpenGL -framework AppKit -Wall -Wextra -Werror
	# OS VERSION
	OSX_V		=	$(shell sw_vers -productVersion | sed "s/[0-9]*.//" | sed "s/.[0-9]*$$//")
	ifeq (${OSX_V}, 14)
		MINILIBDIR	= ./includes/minilibx_pre_catalina
	else
		MINILIBDIR	= ./includes/minilibx
	endif
endif

MINILIB		= ${MINILIBDIR}/libmlx.a

$(NAME):	${OBJS} ${LIBFT} ${MINILIB} ${BMPS}
			@echo "miniRT - compiling"
			${CC} ${CFLAGS} ${VPATH} ${PATHLIB} ${OBJS} ${MINILIB} \
			${LIBFTDIR}/${LIBFT} ${CFLAGS} -o ${NAME}
			@echo "done."

$(LIBFT):	${LIBFTDIR}
			@cd ${LIBFTDIR} && make bonus

$(MINILIB):	${MINILIBDIR}
			@cd ${MINILIBDIR} && make

$(BMPS):
			@mkdir -p bmps

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ${LIBFTDIR} && make $@
			cd ${MINILIBDIR} && $@ || rm -rf *.a *.o

run:		${NAME}
			./${NAME} scenes/nine_spheres.rt

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

.PHONY:		all clean fclean re run
