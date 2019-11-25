SRCSC		= ft_printf.c\
				ft_infos.c\
				ft_convert.c\
				ft_flags.c\
				ft_istype.c\
				ft_utils_str.c

SBONUS		= ft_printf_bonus.c

SRCSH		= ft_printf.h

OBJS		= $(SRCSC:%.c=%.o)

OBONUS		= $(SBONUS:%.c=%.o)

LIBFTDIR	= libft

LIBFT		= libft/libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} libft
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFT}

libft:
			@(cd $(LIBFT) && $(MAKE))

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBONUS}

fclean:		clean
			${RM} ${NAME}

clean_lib:
			@(cd libft && $(MAKE) $@)

re:			fclean all

bonus:		all ${OBONUS}
			${AR} ${NAME} ${OBONUS}

test:		all
			${CC} ${CFLAGS} ${NAME} ${SRCSC} main.c libft/*.c

.PHONY:		all clean fclean re
