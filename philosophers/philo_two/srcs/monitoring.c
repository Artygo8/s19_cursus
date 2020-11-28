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
	sem_post(data->deads);
	return (NULL);
}

void	*ft_all_alive(void *data_ptr)
{
	t_data	*data;

	data = data_ptr;
	sem_wait(data->deads);
	return (NULL);
}

void	*ft_countdown(void *philo_ptr)
{
	int		i;
	t_philo	*cur_phi;
	t_data	*data;

	i = 0;
	cur_phi = philo_ptr;
	data = cur_phi->data;
	gettimeofday(cur_phi->last_meal, NULL);
	while (ft_time_elapsed_ms(cur_phi->last_meal) <
												cur_phi->data->input->time_die)
		msleep(1);
	ft_put_action(cur_phi, DYING);
	sem_post(data->deads);
	return (NULL);
}
