SRCS	= srcs/main.c \
		srcs/monitoring.c \
		srcs/utils/format.c \
		srcs/utils/time.c \
		srcs/data/data.c \
		srcs/data/input.c \
		srcs/data/philo.c

OBJ		= $(SRCS:.c=.o)

NAME	= philo_one

CC		= gcc
FLAGS	= -pthread -Wall -Wextra -Werror

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
