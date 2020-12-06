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

t_data	**get_data()
{
	static t_data *data;

	return (&data);
}

/*
** 
*/

int		ft_set_data()
{
	t_data	*data;

	if (!(*get_data() = (t_data *)malloc(sizeof(t_data))))
		return (ft_error(ERROR_MALLOC_FAIL));
	data = *get_data(); 
	data->finish = 0;
	if (pthread_mutex_init(&(data->no_dead_lock), NULL)
	|| pthread_mutex_init(&(data->block), NULL))
	{
		free(data);
		return (ERROR);
	}
	pthread_mutex_lock(&(data->block));
	data->table = ft_table_dup();
	pthread_mutex_unlock(&(data->block));
	pthread_mutex_lock(&(data->no_dead_lock));
	if (pthread_create(&(data->all_done_eating), NULL, ft_all_done_eating, data)
	|| pthread_create(&(data->all_alive), NULL, ft_all_done_eating, data))
	{
		free(data);
		return (ft_error(ERROR_PTHREAD_CREATE));
	}
	return (0);
}

int		ft_delete_data()
{
	ft_delete_table((*get_data())->table);
	pthread_mutex_lock(&((*get_data())->no_dead_lock));
	pthread_mutex_unlock(&((*get_data())->no_dead_lock));
	pthread_mutex_destroy(&((*get_data())->no_dead_lock));
	pthread_mutex_unlock(&((*get_data())->block));
	pthread_mutex_destroy(&((*get_data())->block));
	free(*get_data());
	return (0);
}
