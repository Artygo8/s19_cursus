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
	next_phi = &(*ft_get_table())[cur_phi->id % *get_input(NB_PHILO)];
	cur_phi->last_meal_ms = ft_get_ms();
	pthread_create(&countdown, NULL, ft_countdown, cur_phi);
	while (cur_phi->eat_count < *get_input(NB_MUST_EAT)
		|| !*get_input(IS_FINITE))
	{
		ft_put_action(cur_phi->id, THINKING);
		get_forks(cur_phi, next_phi);
		cur_phi->last_meal_ms = ft_get_ms();
		ft_put_action(cur_phi->id, EATING);
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
	pthread_t	all_alive;
	pthread_t	all_done_eating;

	pthread_mutex_lock(ft_get_mutex(NO_DEADS));
	i = -1;
	while (++i < *get_input(NB_PHILO))
		pthread_create(&(((*ft_get_table())[i]).live), NULL, living,
											(void*)&((*ft_get_table())[i]));
	pthread_create(&all_done_eating, NULL, ft_all_done_eating, NULL);
	pthread_create(&all_alive, NULL, ft_all_alive, NULL);
	pthread_join(all_alive, NULL);
	i = -1;
	while (++i < *get_input(NB_PHILO))
		pthread_detach(&(((*ft_get_table())[i]).live));
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
	if ((ret = ft_init_table()))
		return (ret);
	ft_philosophing();
	return (0);
}
