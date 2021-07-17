/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:37:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/07 15:37:12 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_all_done_eating(void *data_ptr)
{
	ssize_t		i;
	t_data		*data;

	i = 0;
	data = data_ptr;
	while (i < *get_input(NB_PHILO))
		pthread_join((((data->table)[i++])->live), NULL);
	return (NULL);
}

void	*ft_countdown(void *philo_ptr)
{
	t_philo	*cur_phi;

	cur_phi = philo_ptr;
	cur_phi->last_meal = ft_get_ms();
	while (ft_time_elapsed_ms(cur_phi->last_meal) < *get_input(TIME_TO_DIE)
	&& (!(*get_data())->one_dead || cur_phi->eat_count == 0))
		msleep(1);
	if ((cur_phi->eat_count < *get_input(NB_MUST_EAT)
	|| (!*get_input(IS_FINITE) && !(*get_data())->one_dead)))
		ft_put_action(cur_phi->id, DYING);
	return (NULL);
}

void	get_forks(t_philo *cur_phi, t_philo *next_phi)
{
	while (cur_phi->eat_count > (*get_data())->total_eat / *get_input(NB_PHILO)
	&& !(*get_data())->one_dead)
		usleep(5);
	if (ft_time_elapsed_ms(*get_input(START)) < 5 && cur_phi->id % 2)
		msleep(1);
	if (*get_input(NB_PHILO) == 1)
	{
		pthread_mutex_lock(&(cur_phi->fork));
		ft_put_action(cur_phi->id, FORKING);
		msleep(*get_input(TIME_TO_DIE) + 10);
	}
	else if ((cur_phi->id + next_phi->id) % 2)
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
	t_philo		*cur_phi;
	t_philo		*next_phi;

	pthread_mutex_lock(&((*get_data())->block));
	pthread_mutex_unlock(&((*get_data())->block));
	cur_phi = philo;
	next_phi = (*get_data())->table[cur_phi->id % *get_input(NB_PHILO)];
	while ((cur_phi->eat_count < *get_input(NB_MUST_EAT)
	|| !*get_input(IS_FINITE)) && !(*get_data())->one_dead)
	{
		ft_put_action(cur_phi->id, THINKING);
		get_forks(cur_phi, next_phi);
		cur_phi->last_meal = ft_get_ms();
		ft_put_action(cur_phi->id, EATING);
		msleep(*get_input(TIME_TO_EAT));
		pthread_mutex_unlock(&(cur_phi->fork));
		pthread_mutex_unlock(&(next_phi->fork));
		if ((++(cur_phi->eat_count) >= *get_input(NB_MUST_EAT)
			&& *get_input(IS_FINITE)))
			break ;
		ft_put_action(cur_phi->id, SLEEPING);
		msleep(*get_input(TIME_TO_SLEEP));
	}
	return (NULL);
}
