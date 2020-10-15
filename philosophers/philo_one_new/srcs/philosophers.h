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
# define ERROR_ARGUMENTS "Error: wrong number of arguments\n"

typedef struct	timeval t_tv;
typedef struct	s_philosophers t_philo;

typedef struct	s_all_variables
{
	size_t			nb_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			nb_must_eat;
	t_tv			*start_tv;
	pthread_mutex_t	no_dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	binary_lock[2];
	t_philo			**table;
}				t_vars;

struct	s_philosophers
{
	int				id;
	size_t			eat_count;
	pthread_t		live;
	pthread_mutex_t	fork;
	t_tv			*last_meal;
};

// init-end.c
int     *ids_initializer(void);
t_tv	*ft_timedup(void);
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
