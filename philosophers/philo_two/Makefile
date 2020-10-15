SRCS	= srcs/main.c \
		srcs/utils/format.c \
		srcs/utils/time.c \
		srcs/monitoring.c \
		srcs/init-end.c

OBJ		= $(SRCS:.c=.o)

NAME	= philo_two

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

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
