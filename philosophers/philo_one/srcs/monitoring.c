/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:42:36 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:42:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_all_done_eating(void *data_ptr)
{
	int		i;
	t_data	*data;

	i = 0;
	data = data_ptr;
	while ((data->table)[i])
		pthread_join((((data->table)[i++])->live), NULL);
	// pthread_mutex_unlock(&(data->no_dead_lock));
	pthread_mutex_lock(&(data->write_lock));
	return (NULL);
}

void	*ft_all_alive(void *data_ptr)
{
	t_data	*data;

	data = data_ptr;
	pthread_mutex_lock(&(data->no_dead_lock));
	pthread_mutex_unlock(&(data->no_dead_lock));
	*get_input(NB_MUST_EAT) = 0;
	*get_input(IS_FINITE) = 1;
	return (NULL);
}

void	*ft_countdown(void *philo_ptr)
{
	t_philo	*cur_phi;

	cur_phi = philo_ptr;
	cur_phi->last_meal = ft_get_ms();
	while (ft_time_elapsed_ms(cur_phi->last_meal) < *get_input(TIME_TO_DIE))
		msleep(1);
	if (cur_phi->eat_count >= *get_input(NB_MUST_EAT) && *get_input(IS_FINITE))
		return (NULL);
	ft_put_action(cur_phi->id, DYING);
	pthread_mutex_unlock(&((*get_data())->no_dead_lock));
	return (NULL);
}
