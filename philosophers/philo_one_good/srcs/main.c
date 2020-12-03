/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:42:36 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:42:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_forks(t_philo *cur_phi, t_philo *next_phi)
{
	if (ft_time_elapsed_ms(*get_input(START)) < 5 && cur_phi->id % 2)
		msleep(1);
	if ((cur_phi->id + next_phi->id) % 2)
	{
		pthread_mutex_lock(&(cur_phi->fork));
		ft_put_action(cur_phi, FORKING);
		pthread_mutex_lock(&(next_phi->fork));
		ft_put_action(cur_phi, FORKING);
	}
	else
	{
		pthread_mutex_lock(&(next_phi->fork));
		ft_put_action(cur_phi, FORKING);
		pthread_mutex_lock(&(cur_phi->fork));
		ft_put_action(cur_phi, FORKING);
	}
}

void	*living(void *philo)
{
	pthread_t	countdown;
	t_data		*data;
	t_philo		*cur_phi;
	t_philo		*next_phi;

	cur_phi = philo;
	data = cur_phi->data;
	next_phi = data->table[cur_phi->id % *get_input(NB_PHILO)];
	cur_phi->last_meal = ft_get_ms();
	pthread_create(&countdown, NULL, ft_countdown, cur_phi);
	while (cur_phi->eat_count < *get_input(NB_MUST_EAT)
		|| !*get_input(IS_FINITE))
	{
		ft_put_action(cur_phi, THINKING);
		get_forks(cur_phi, next_phi);
		cur_phi->last_meal = ft_get_ms();
		ft_put_action(cur_phi, EATING);
		msleep(*get_input(TIME_TO_EAT));
		ft_put_action(cur_phi, SLEEPING);
		pthread_mutex_unlock(&(cur_phi->fork));
		pthread_mutex_unlock(&(next_phi->fork));
		msleep(*get_input(TIME_TO_SLEEP));
		cur_phi->eat_count++;
	}
	pthread_detach(countdown);
	return (NULL);
}

void	ft_philosophing()
{
	int			i;
	t_data		*data;
	pthread_t	all_alive;
	pthread_t	all_done_eating;

	data = *get_data();
	pthread_mutex_lock(&(data->no_dead_lock));
	i = -1;
	while ((data->table)[++i])
		pthread_create(&(((data->table)[i])->live), NULL, living,
											(void*)((data->table)[i]));
	pthread_create(&all_done_eating, NULL, ft_all_done_eating, data);
	pthread_create(&all_alive, NULL, ft_all_alive, data);
	pthread_join(all_alive, NULL);
	i = -1;
	while ((data->table)[++i])
		pthread_detach((((data->table)[i])->live));
	pthread_detach(all_alive);
	pthread_detach(all_done_eating);
}

int		main(int argc, char const *argv[])
{
	int		ret;

	if (argc != 5 && argc != 6)
        return (ft_error(ERROR_NB_ARG));		
	if ((ret = set_input(argc, argv)))
		return (ret);
	if ((ret = ft_set_data()))
		return (ret);
	ft_philosophing();
	return (ft_delete_data());
}
