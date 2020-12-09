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

void	get_forks(t_philo *philo)
{
	t_data	*data;

	data = *get_data();
	while (philo->eat_count > data->total_eat / *get_input(NB_PHILO)
	&& !data->one_dead)
		usleep(5);
	sem_wait(data->tickets);
	sem_wait(data->forks);
	ft_put_action(philo->id, FORKING);
	if (*get_input(NB_PHILO) == 1)
	{
		msleep(*get_input(TIME_TO_DIE) + 10);
		return ;
	}
	sem_wait(data->forks);
	sem_post(data->tickets);
	ft_put_action(philo->id, FORKING);
}

void	*living(void *philo)
{
	t_philo		*cur_phi;
	t_data		*data;

	while ((*get_data())->one_dead == -1)
		usleep(10);
	cur_phi = philo;
	data = *get_data();
	while ((cur_phi->eat_count < *get_input(NB_MUST_EAT)
	|| !*get_input(IS_FINITE)) && !(*get_data())->one_dead)
	{
		ft_put_action(cur_phi->id, THINKING);
		get_forks(cur_phi);
		cur_phi->last_meal = ft_get_ms();
		ft_put_action(cur_phi->id, EATING);
		msleep(*get_input(TIME_TO_EAT));
		sem_post(data->forks);
		sem_post(data->forks);
		if ((++(cur_phi->eat_count) >= *get_input(NB_MUST_EAT)
			&& *get_input(IS_FINITE)))
			break ;
		ft_put_action(cur_phi->id, SLEEPING);
		msleep(*get_input(TIME_TO_SLEEP));
	}
	return (NULL);
}
