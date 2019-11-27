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

SRCSC		= ft_printf.c\
				ft_infos.c\
				ft_convert.c\
				ft_flags.c\
				ft_istype.c\
				ft_ftoa.c\
				ft_utils_str.c

SRCSH		= ft_printf.h

OBJS		= $(SRCSC:%.c=%.o)

LIBFTDIR	= libft

LIBFT		= libft/libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} ${LIBFT}
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFT}


$(LIBFT):
			cd ${LIBFTDIR} && make && make clean && cd ..

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean fcleanlib
			${RM} ${NAME}

fcleanlib:
			cd ${LIBFTDIR} && make fclean && cd ..

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re
