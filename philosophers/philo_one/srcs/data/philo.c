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

t_philo	*ft_philo_dup(int id)
{
	t_philo	*new;

	new = (t_philo*)malloc(sizeof(t_philo));
	memset(new, 0, sizeof(t_philo));
	new->id = id;
	new->eat_count = 0;
	pthread_mutex_init(&(new->fork), NULL);
	new->last_meal = ft_get_ms();
	return (new);
}

t_philo	**ft_table_dup()
{
	ssize_t		id;
	t_philo		**table;

	id = 0;
	table = (t_philo **)malloc((*get_input(NB_PHILO) + 1) * sizeof(t_philo *));
	memset(table, 0, (*get_input(NB_PHILO) + 1) * sizeof(t_philo *));
	while (id++ < *get_input(NB_PHILO))
		table[id - 1] = ft_philo_dup(id);
	table[id - 1] = NULL;
	return (table);
}

void	ft_delete_table(t_philo **table)
{
	int id;

	id = 0;
	while (table[id])
	{
		// pthread_mutex_lock(&(table[id]->fork));
		pthread_mutex_unlock(&(table[id]->fork));
		pthread_mutex_destroy(&(table[id]->fork));
		free(table[id++]);
	}
	free(table);
}
