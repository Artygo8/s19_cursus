/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:34:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 17:34:38 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo		**ft_get_table(void)
{
	static t_philo	*table;

	return (&table);
}

t_philo		ft_new_philo(int id)
{
	t_philo	philo;

	philo.id = id;
	philo.eat_count = 0;
	philo.live = 0;
	pthread_mutex_init(&(philo.fork), NULL);
	philo.last_meal_ms = ft_get_ms();
	return (philo);
}

int			ft_init_table(void)
{
	int			id;
	int			nb_philo;

	id = 0;
	nb_philo = *get_input(NB_PHILO);
	if (!(*ft_get_table() = (t_philo *)malloc((nb_philo) * sizeof(t_philo))))
		return (ft_error(ERROR_MALLOC_FAIL));
	while (id++ < nb_philo)
		(*ft_get_table())[id - 1] = ft_new_philo(id);
	return (0);
}

void		ft_delete_table(void)
{
	free(*ft_get_table());
}