/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:34:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 17:34:38 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	**get_data(void)
{
	static t_data *data;

	return (&data);
}

int		ft_set_data(void)
{
	t_data	*data;

	if (!(*get_data() = (t_data *)malloc(sizeof(t_data))))
		return (ft_error(ERROR_MALLOC_FAIL));
	data = *get_data();
	data->one_dead = FALSE;
	sem_unlink(SEM_FNAME_DEAD);
	sem_unlink(SEM_FNAME_WRITE);
	sem_unlink(SEM_FNAME_TICKETS);
	sem_unlink(SEM_FNAME_FORKS);
	data->dead = sem_open(SEM_FNAME_DEAD, O_CREAT, 0660, 0);
	data->write = sem_open(SEM_FNAME_WRITE, O_CREAT, 0660, 1);
	data->tickets = sem_open(SEM_FNAME_TICKETS, O_CREAT, 0660, 1);
	data->forks =
		sem_open(SEM_FNAME_FORKS, O_CREAT, 0660, *get_input(NB_PHILO));
	return (0);
}
