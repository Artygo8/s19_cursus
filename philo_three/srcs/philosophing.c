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

void	*ft_check_for_dead(void *nothing)
{
	t_data	*data;

	data = *get_data();
	sem_wait(data->dead);
	data->one_dead = TRUE;
	sem_post(data->dead);
	return (nothing);
}

void	*ft_countdown(void *philo_ptr)
{
	t_philo	*cur_phi;

	cur_phi = philo_ptr;
	cur_phi->last_meal = ft_get_ms();
	while (ft_time_elapsed_ms(cur_phi->last_meal) < *get_input(TIME_TO_DIE)
	&& (!(*get_data())->one_dead || cur_phi->eat_count == 0) && cur_phi->id)
		msleep(1);
	if ((cur_phi->eat_count < *get_input(NB_MUST_EAT)
	|| (!*get_input(IS_FINITE) && !(*get_data())->one_dead)) && cur_phi->id)
		ft_put_action(cur_phi->id, DYING);
	return (NULL);
}

void	get_forks(int id)
{
	t_data	*data;

	data = *get_data();
	sem_wait(data->tickets);
	sem_wait(data->forks);
	ft_put_action(id, FORKING);
	sem_wait(data->forks);
	sem_post(data->tickets);
	ft_put_action(id, FORKING);
}

int		living(t_philo *cur_phi)
{
	t_data		*data;
	pthread_t	check_dead;

	pthread_create(&(cur_phi->countdown), NULL, ft_countdown, cur_phi);
	pthread_detach(cur_phi->countdown);
	pthread_create(&check_dead, NULL, ft_check_for_dead, NULL);
	pthread_detach(check_dead);
	data = *get_data();
	while ((cur_phi->eat_count < *get_input(NB_MUST_EAT)
	|| !*get_input(IS_FINITE)) && !(*get_data())->one_dead)
	{
		ft_put_action(cur_phi->id, THINKING);
		get_forks(cur_phi->id);
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
	return (0);
}
