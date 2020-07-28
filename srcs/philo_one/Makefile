SRCS	= srcs/main.c \
		srcs/utils/format.c \
		srcs/utils/time.c \
		srcs/monitoring.c \
		srcs/init-end.c

NAME	= philo_one

FLAGS	= -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	./$(NAME)

re: clean all

clean:
	rm -f $(NAME)
