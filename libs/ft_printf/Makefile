# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 15:08:48 by agossuin          #+#    #+#              #
#    Updated: 2019/12/18 13:57:47 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= ft_printf.c\
				ft_infos.c\
				ft_convert.c\
				ft_flags.c\
				ft_istype.c

SRCSH		= ft_printf.h

OBJS		= $(SRCSC:%.c=%.o)

LIBFTDIR	= libft

LIBFT		= libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} ${LIBFT}
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFTDIR}/*.o


$(LIBFT):
			cd ${LIBFTDIR} && make $@

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ${LIBFTDIR} && make $@

fclean:		clean
			${RM} ${NAME}
			cd ${LIBFTDIR} && make $@

re:			fclean all

bonus:		all

test:		re
			@${CC} main.c ${NAME}
			make clean
			@echo "\n================" 
			@./a.out
			@echo "\n================" 


.PHONY:		all clean fclean re
