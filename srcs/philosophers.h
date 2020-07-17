#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

# define NUMBER_OF_PHILOSOPHERS 10
# define TIME_TO_DIE 5
# define TIME_TO_EAT 500000
# define TIME_TO_SLEEP 500000
# define NUMBER_OF_TIME_EACH_PHILOSOPHER_MUST_EAT 1

struct timeval  *g_start;
pthread_mutex_t g_write_lock;
pthread_mutex_t g_forks[NUMBER_OF_PHILOSOPHERS];

int	    ft_putnbr(int n);
void    ft_put_timestamp(int id, const char *arg);

# endif