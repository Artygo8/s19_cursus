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

# define MAX_ULONG "4294967295"
# define INT_MIN -2147483648

# define FALSE 0
# define TRUE 1

typedef struct timeval			t_tv;
typedef struct s_philosophers	t_philo;
typedef int						t_bool;

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
};

int					*get_input(int e_input);
int					set_input(int argc, char const *argv[]);

/*
** MUTEX.C
*/

# define SIZE_MUTEX 4

enum e_mutex {
	NO_DEADS,
	WRITE,
	BINARY1,
	BINARY2,
};

pthread_mutex_t		*ft_get_mutex(int e_mutex);
void				ft_init_mutex(void);

/*
** PHILO.C
*/

struct				s_philosophers
{
	int				id;
	size_t			eat_count;
	pthread_t		live;
	pthread_mutex_t	fork;
	size_t			last_meal_ms;
};

t_philo				**ft_get_table(void);
t_philo				ft_new_philo(int id);
int					ft_init_table(void);
void				ft_delete_table(void);

/*
** ERRORS.C
*/

enum e_error {
	ERROR_NB_ARG = 1,
	ERROR_NOT_ULONG,
	ERROR_MALLOC_FAIL,
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
	DYING
};

void				ft_put_action(int id, int e_action);

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

int					ft_time_elapsed_ms(size_t origin_ms);
void				ft_put_abs_time(void);
size_t				ft_get_ms(void);
void				msleep(int time);

/*
** MONITORING.C
*/

void				*ft_all_done_eating(void);
void				*ft_all_alive(void);
void				*ft_countdown(void *philo_ptr);

#endif
