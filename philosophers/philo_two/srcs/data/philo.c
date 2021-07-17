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

t_philo	*ft_philo_create(int id)
{
	pthread_t	countdown;
	t_philo		*new;

	if (!(new = (t_philo*)malloc(sizeof(t_philo))))
		return (NULL);
	memset(new, 0, sizeof(t_philo));
	new->id = id;
	new->eat_count = 0;
	new->last_meal = ft_get_ms();
	pthread_create(&(new->live), NULL, living, (void*)(new));
	pthread_create(&countdown, NULL, ft_countdown, new);
	pthread_detach(countdown);
	return (new);
}

t_philo	**ft_table_dup(void)
{
	ssize_t		id;
	ssize_t		tot;
	t_philo		**table;

	id = 0;
	tot = *get_input(NB_PHILO);
	if (!(table = (t_philo **)malloc((tot + 1) * sizeof(t_philo *))))
		return (NULL);
	memset(table, 0, (tot + 1) * sizeof(t_philo *));
	while (id++ < tot)
		table[id - 1] = ft_philo_create(id);
	table[id - 1] = NULL;
	return (table);
}

void	ft_delete_table(t_philo **table)
{
	int id;

	id = 0;
	while (table[id])
		free(table[id++]);
	free(table);
}
