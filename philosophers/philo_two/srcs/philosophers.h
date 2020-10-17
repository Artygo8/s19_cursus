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
# include <fcntl.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include <semaphore.h>
# include <string.h>

# define FORKING " has taken fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DYING " died"
# define ERROR_ARGUMENTS "Error: wrong number of arguments\n"
# define ERROR_FORMAT "Error: argument not unsigned longs\n"

# define SEM_FNAME_DEADS "/deads"
# define SEM_FNAME_WRITE "/write"
# define SEM_FNAME_TICKETS "/tickets"
# define SEM_FNAME_FORKS "/forks"

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

/*
** ticket is needed to have access to the forks.
*/

typedef struct		s_data
{
	t_tv			*start_tv;
	t_input			*input;
	sem_t			*deads;
	sem_t			*write;
	sem_t			*tickets;
	sem_t			*forks;
	t_philo			**table;
}					t_data;

struct				s_philosophers
{
	int				id;
	size_t			eat_count;
	pthread_t		live;
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

void				ft_unlink_sem(void);
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
