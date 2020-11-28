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

#include "../philosophers.h"

void	ft_unlink_sem(void)
{
	sem_unlink(SEM_FNAME_DEADS);
	sem_unlink(SEM_FNAME_WRITE);
	sem_unlink(SEM_FNAME_TICKETS);
	sem_unlink(SEM_FNAME_FORKS);
}

t_data	*ft_data_dup(t_input *input)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->start_tv = ft_timedup();
	data->input = input;
	data->deads = sem_open(SEM_FNAME_DEADS, O_CREAT, 0660, 0);
	data->write = sem_open(SEM_FNAME_WRITE, O_CREAT, 0660, 1);
	if (input->nb_philo > 2)
		data->tickets = sem_open(SEM_FNAME_TICKETS, O_CREAT, 0660, input->nb_philo / 2 + (input->nb_philo % 2));
	else
		data->tickets = sem_open(SEM_FNAME_TICKETS, O_CREAT, 0660, 1);
	data->forks = sem_open(SEM_FNAME_FORKS, O_CREAT, 0660, input->nb_philo);
	if (data->deads == SEM_FAILED || data->write == SEM_FAILED
	|| data->forks == SEM_FAILED || data->tickets == SEM_FAILED)
	{
		free(data->start_tv);
		free(data);
		return (NULL);
	}
	data->table = ft_table_dup(input->nb_philo);
	return (data);
}

void	ft_delete_data(t_data *data)
{
	free(data->start_tv);
	sem_close(data->deads);
	sem_close(data->write);
	sem_close(data->tickets);
	sem_close(data->forks);
	ft_delete_table(data->table);
}
