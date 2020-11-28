SRCS	= srcs/main.c \
		srcs/monitoring.c \
		srcs/utils/format.c \
		srcs/utils/time.c \
		srcs/utils/strings.c \
		srcs/utils/numbers.c \
		srcs/utils/errors.c \
		srcs/data/mutex.c \
		srcs/data/input.c \
		srcs/data/philo.c

OBJ		= $(SRCS:%c=%o)

NAME	= philo_one

CC		= gcc
CFLAGS	= -pthread -Wall -Wextra -Werror -I srcs/.

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

test:$(NAME)
	./$(NAME)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

%o:%c
	$(CC) $(CFLAGS) -o $@ -c $<
