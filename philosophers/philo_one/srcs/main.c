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
	t_data			*data;

	data = cur_phi->data;
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
	next_phi = data->table[cur_phi->id % data->input->nb_philo];
	gettimeofday(cur_phi->last_meal, NULL);
	pthread_create(&countdown, NULL, ft_countdown, cur_phi);
	while (cur_phi->eat_count < data->input->nb_must_eat
		|| !data->input->finite)
	{
		ft_put_action(cur_phi, THINKING);
		get_forks(cur_phi, next_phi);
		gettimeofday(cur_phi->last_meal, NULL);
		ft_put_action(cur_phi, EATING);
		msleep(data->input->time_eat);
		ft_put_action(cur_phi, SLEEPING);
		pthread_mutex_unlock(&(cur_phi->fork));
		pthread_mutex_unlock(&(next_phi->fork));
		msleep(data->input->time_sleep);
		cur_phi->eat_count++;
	}
	pthread_detach(countdown);
	return (NULL);
}

void	ft_philosophing(t_input *input)
{
	int			i;
	t_data		*data;
	pthread_t	all_alive;
	pthread_t	all_done_eating;

	data = ft_data_dup(input);
	ft_data_to_philo(data);
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
		pthread_detach(&(((data->table)[i])->live));
	pthread_detach(all_alive);
	pthread_detach(all_done_eating);
	ft_delete_data(data);
}

int		main(int argc, char const *argv[])
{
	int		ret;
	t_input	*input;

	if (argc == 5 || argc == 6)
	{
		if (!(input = ft_input_dup(argc, argv)))
			return (1);
		ft_philosophing(input);
		free(input);
		return (0);
	}
	write(2, ERROR_ARGUMENTS, ft_strlen(ERROR_ARGUMENTS));
	return (1);
}
