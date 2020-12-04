#include "philosophers.h"

void	get_forks(t_philo *cur_phi, t_philo *next_phi)
{
	if (ft_time_elapsed_ms(*get_input(START)) < 5 && cur_phi->id % 2)
		msleep(1);
	if ((cur_phi->id + next_phi->id) % 2)
	{
		pthread_mutex_lock(&(cur_phi->fork));
		ft_put_action(cur_phi->id, FORKING);
		pthread_mutex_lock(&(next_phi->fork));
		ft_put_action(cur_phi->id, FORKING);
	}
	else
	{
		pthread_mutex_lock(&(next_phi->fork));
		ft_put_action(cur_phi->id, FORKING);
		pthread_mutex_lock(&(cur_phi->fork));
		ft_put_action(cur_phi->id, FORKING);
	}
}

void	*living(void *philo)
{
	pthread_t	countdown;
	t_philo		*cur_phi;
	t_philo		*next_phi;

	cur_phi = philo;
	next_phi = (*get_data())->table[cur_phi->id % *get_input(NB_PHILO)];
	cur_phi->last_meal = ft_get_ms();
	pthread_create(&countdown, NULL, ft_countdown, cur_phi);
    pthread_detach(countdown);
	while (cur_phi->eat_count < *get_input(NB_MUST_EAT)
    || !*get_input(IS_FINITE))
	{
		ft_put_action(cur_phi->id, THINKING);
		get_forks(cur_phi, next_phi);
		cur_phi->last_meal = ft_get_ms();
		ft_put_action(cur_phi->id, EATING);
		msleep(*get_input(TIME_TO_EAT));
		ft_put_action(cur_phi->id, SLEEPING);
		pthread_mutex_unlock(&(cur_phi->fork));
		pthread_mutex_unlock(&(next_phi->fork));
		msleep(*get_input(TIME_TO_SLEEP));
		cur_phi->eat_count++;
	}
	return (NULL);
}

int		ft_create_phi_threads()
{
	int			i;
	int			ret;
	t_data		*data;

	i = -1;
	ret = 0;
	data = *get_data();
	while ((data->table)[++i])
		ret |= pthread_create(&(((data->table)[i])->live), NULL, living,
											(void*)((data->table)[i]));
	ret |= pthread_create(&(data->all_done_eating), NULL, ft_all_done_eating, data);
	ret |= pthread_create(&(data->all_alive), NULL, ft_all_alive, data);
	if (ret)
		return (ft_error(ERROR_PTHREAD_CREATE));
	return (0);
}

int		ft_detach_phi_threads()
{
	int			i;
	int			ret;
	t_data		*data;

	i = -1;
	ret = 0;
	data = *get_data();
	while ((data->table)[++i])
		ret |= pthread_detach((((data->table)[i])->live));
	ret |= pthread_detach(data->all_alive);
	ret |= pthread_detach(data->all_done_eating);
	if (ret)
		return (ft_error(ERROR_PTHREAD_DETACH));
	return (0);
}

int		ft_philosophing()
{
	int			ret;
	t_data		*data;

	data = *get_data();
	if (pthread_mutex_lock(&(data->no_dead_lock)))
		return (ft_error(ERROR_MUTEX_LOCK));
	if ((ret = ft_create_phi_threads()))
	{
		ft_detach_phi_threads();
		return (ret);
	}
	if (pthread_join(data->all_done_eating, NULL))
	{
		ft_detach_phi_threads();
		return (ft_error(ERROR_PTHREAD_JOIN));
	}
    ft_detach_phi_threads();
	return (0);
}
