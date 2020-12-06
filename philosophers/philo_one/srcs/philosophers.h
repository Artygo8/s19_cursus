/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:42:36 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:42:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include <string.h>

# define RD "\e[31m"
# define GN "\e[32m"
# define YW "\e[33m"
# define BE "\e[34m"
# define NC "\e[0m"

# define MAX_USEC 999999
# define MAX_ULONG "4294967295"
# define INT_MIN -2147483648

# define FALSE 0
# define TRUE 1

typedef struct timeval			t_tv;
typedef struct s_philosophers	t_philo;
typedef int						t_bool;

typedef struct		s_data
{
	t_bool			finish;
	pthread_mutex_t	no_dead_lock;
	pthread_mutex_t	block;
	t_philo			**table;
	pthread_t		all_done_eating;
	pthread_t		all_alive;
}					t_data;

struct				s_philosophers
{
	int				id;
	ssize_t			eat_count;
	ssize_t			last_meal;
	pthread_mutex_t	fork;
	pthread_t		live;
};

/*
** INPUT.C
*/

# define SIZE_INPUTS 6

enum e_input{
	NB_PHILO,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	IS_FINITE,
	NB_MUST_EAT,
	START,
};

ssize_t				*get_input(int e_input);
int					set_input(int argc, char const *argv[]);

/*
** ERRORS.C
*/

enum e_error {
	ERROR = 1,
	ERROR_NB_ARG,
	ERROR_NOT_ULONG,
	ERROR_MALLOC_FAIL,
	ERROR_PTHREAD_JOIN,
	ERROR_PTHREAD_DETACH,
	ERROR_PTHREAD_CREATE,
	ERROR_MUTEX_LOCK,
	ERROR_MUTEX_UNLOCK,
	ERROR_MUTEX_INIT,
	ERROR_MUTEX_DESTROY,
	ERROR_GTOD,
	ERROR_USLEEP,
};

int     			ft_error(int e_error);

/*
** FORMAT.C
*/

enum e_action {
	FORKING,
	EATING,
	SLEEPING,
	THINKING,
	DYING,
};

int					ft_put_action(size_t id, int e_action);

/*
** NUMBERS.C
*/

size_t				ft_atoi(const char *str);
int					ft_gt_max_ulong(const char *str);
int					ft_is_ulong(const char *str);
void				ft_putunbr(size_t n);

/*
** STRINGS.C
*/

size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char *str, int fd);

/*
** TIME.C
*/

ssize_t				ft_time_elapsed_ms(ssize_t origin_ms);
ssize_t				ft_put_abs_time(void);
ssize_t				ft_get_ms(void);
void				msleep(ssize_t time);

void				*ft_all_done_eating(void *data_ptr);
void				*ft_all_alive(void *data_ptr);
void				*ft_countdown(void *philo_ptr);

int					ft_int_width(int n);
void				ft_debug(t_data *data, const char *str);

t_data				**get_data();
int					ft_set_data();
int					ft_delete_data();

size_t				ft_atoi(const char *str);
int					ft_gt_max_ulong(const char *str);
int					ft_is_ulong(const char *str);

t_philo				*ft_philo_create(int id);
t_philo				**ft_table_dup();
void				ft_data_to_philo(t_data *data);
void				ft_delete_table(t_philo **table);


void	*living(void *philo);
int		ft_philo_thread_create();
int		ft_philosophing();

#endif
