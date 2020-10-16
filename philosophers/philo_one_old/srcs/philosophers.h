#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

# define NUMBER_OF_PHILOSOPHERS 3
# define TIME_TO_DIE 3000
# define TIME_TO_EAT 100
# define TIME_TO_SLEEP 100
# define NUMBER_OF_TIME_EACH_PHILOSOPHER_MUST_EAT 2

// actions
# define FORKING " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DYING " died"

struct timeval  *g_start_tv;
pthread_mutex_t g_no_dead_lock;
pthread_mutex_t g_write_lock;
pthread_mutex_t g_binary_lock[2];
pthread_mutex_t g_forks[NUMBER_OF_PHILOSOPHERS];
pthread_t g_philosopher[NUMBER_OF_PHILOSOPHERS];

typedef struct timeval t_tv;

// init-end.c
int     *ids_initializer(void);
void    time_initializer(void);
void    mutex_initializer(void);
void    mutex_destroyer(void);

// monitoring
void    *ft_all_done_eating(void *unused);
void    *ft_all_alive(void *unused);
void    *ft_countdown(void *id_ptr);

// utils/format.c
int     ft_strlen(const char *str);
int     ft_int_width(int n);
void    ft_putnbr(int n);
void    put_action(int id, const char *);

// utils/time.c
int     ft_time_elapsed_ms(struct timeval *origin_tv);
void    msleep(int time);

# endif
