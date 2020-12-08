SRCS	= srcs/main.c \
		srcs/philosophing.c \
		srcs/utils/format.c \
		srcs/utils/time.c \
		srcs/utils/strings.c \
		srcs/utils/numbers.c \
		srcs/utils/errors.c \
		srcs/data/data.c \
		srcs/data/input.c \
		srcs/data/philo.c

OBJ		= $(SRCS:%c=%o)

NAME	= philo_three

CC		= gcc
CFLAGS	= -lpthread -Wall -Wextra -Werror -I srcs/.

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

test:$(NAME)
	./$(NAME)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

%o:%c
	$(CC) $(CFLAGS) -o $@ -c $<
