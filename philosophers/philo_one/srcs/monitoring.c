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

void	*ft_all_done_eating(void)
{
	int		i;

	i = 0;
	while (i < *get_input(NB_PHILO))
		pthread_join((((*ft_get_table())[i++]).live), NULL);
	pthread_mutex_lock(ft_get_mutex(WRITE));
	pthread_mutex_unlock(ft_get_mutex(NO_DEADS));
	return (NULL);
}

void	*ft_all_alive(void)
{
	pthread_mutex_lock(ft_get_mutex(NO_DEADS));
	pthread_mutex_unlock(ft_get_mutex(NO_DEADS));
	return (NULL);
}

void	*ft_countdown(void *philo_ptr)
{
	t_philo	*cur_phi;

	cur_phi = philo_ptr;
	cur_phi->last_meal_ms = ft_get_ms();
	while (ft_time_elapsed_ms(cur_phi->last_meal_ms) < *get_input(TIME_TO_DIE))
		msleep(1);
	ft_put_action(cur_phi->id, DYING);
	pthread_mutex_unlock(ft_get_mutex(NO_DEADS));
	return (NULL);
}
