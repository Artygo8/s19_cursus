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

# define FORKING " has taken fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DYING " died"
# define ERROR_ARGUMENTS "Error: wrong number of arguments\n"
# define ERROR_FORMAT "Error: argument not unsigned longs\n"

# define RD "\e[31m"
# define GN "\e[32m"
# define YW "\e[33m"
# define BE "\e[34m"
# define NC "\e[0m"

# define MAX_ULONG "4294967295"
# define INT_MIN -2147483648

# define TRUE 1
# define FALSE 0

typedef struct timeval			t_tv;
typedef struct s_philosophers	t_philo;
typedef int						t_bool;

typedef struct		s_input
{
	size_t			nb_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	t_bool			finite;
	size_t			nb_must_eat;
}					t_input;

typedef struct		s_data
{
	t_tv			*start_tv;
	t_input			*input;
	pthread_mutex_t	no_dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	binary_lock[2];
	t_philo			**table;
}					t_data;

struct				s_philosophers
{
	int				id;
	size_t			eat_count;
	pthread_t		live;
	pthread_mutex_t	fork;
	t_tv			*last_meal;
	t_data			*data;
};

void				*ft_all_done_eating(void *data_ptr);
void				*ft_all_alive(void *data_ptr);
void				*ft_countdown(void *philo_ptr);

int					ft_strlen(const char *str);
int					ft_int_width(int n);
void				ft_putnbr(size_t n);
void				ft_put_action(t_philo *philo, const char *action);
void				ft_debug(t_data *data, const char *str);

int					ft_time_elapsed_ms(struct timeval *origin_tv);
t_tv				*ft_timedup(void);
void				msleep(int time);
void				ft_put_abs_time(struct timeval *origin_tv);

t_data				*ft_data_dup(t_input *input);
void				ft_delete_data(t_data *data);

size_t				ft_atoi(const char *str);
int					ft_gt_max_ulong(const char *str);
int					ft_is_ulong(const char *str);
t_input				*ft_input_dup(int argc, char const *argv[]);

t_philo				*ft_philo_dup(int id);
t_philo				**ft_table_dup(int nb_philo);
void				ft_data_to_philo(t_data *data);
void				ft_delete_table(t_philo **table);

#endif
