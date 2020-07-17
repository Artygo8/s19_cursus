SRCS	= srcs/philosophers.c srcs/utils.c

NAME	= philo


FLAGS	= -Wall -Wextra -Werror

all:	
	$(CC) $(SRCS) -o $(NAME)
	./$(NAME)
