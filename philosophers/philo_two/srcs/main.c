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

void	get_forks(t_philo *philo, t_data *data)
{
	int *test;

	sem_wait(data->tickets);
	sem_wait(data->forks);
	ft_put_action(philo, FORKING);
	sem_wait(data->forks);
	sem_post(data->tickets);
	ft_put_action(philo, FORKING);
}

void	*living(void *philo)
{
	pthread_t	countdown;
	t_data		*data;
	t_philo		*cur_phi;

	cur_phi = philo;
	data = cur_phi->data;
	gettimeofday(cur_phi->last_meal, NULL);
	pthread_create(&countdown, NULL, ft_countdown, cur_phi);
	while (cur_phi->eat_count++ < data->input->nb_must_eat
		|| !data->input->finite)
	{
		ft_put_action(cur_phi, THINKING);
		get_forks(cur_phi, data);
		ft_put_action(cur_phi, EATING);
		gettimeofday(cur_phi->last_meal, NULL);
		msleep(data->input->time_eat);
		ft_put_action(cur_phi, SLEEPING);
		sem_post(data->forks);
		sem_post(data->forks);
		msleep(data->input->time_sleep);
	}
	pthread_detach(countdown);
	return (NULL);
}

int		ft_philosophing(t_input *input)
{
	int			i;
	t_data		*data;
	pthread_t	all_alive;
	pthread_t	all_done_eating;

	ft_unlink_sem();
	if (!(data = ft_data_dup(input)))
		return (EXIT_FAILURE);
	ft_data_to_philo(data);
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
	return (EXIT_SUCCESS);
}

int		main(int argc, char const *argv[])
{
	int		ret;
	t_input	*input;

	ret = EXIT_SUCCESS;
	if (argc == 5 || argc == 6)
	{
		if (!(input = ft_input_dup(argc, argv)))
			return (1);
		if (ft_philosophing(input) == EXIT_FAILURE)
			ret = EXIT_FAILURE;
		free(input);
		return (ret);
	}
	write(2, ERROR_ARGUMENTS, ft_strlen(ERROR_ARGUMENTS));
	return (EXIT_FAILURE);
}
