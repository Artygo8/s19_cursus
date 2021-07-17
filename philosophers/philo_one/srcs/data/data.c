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
	data->total_eat = 0;
	if (pthread_mutex_init(&(data->block), NULL))
	{
		free(data);
		return (ERROR);
	}
	pthread_mutex_lock(&(data->block));
	data->table = ft_table_dup();
	pthread_mutex_unlock(&(data->block));
	if (pthread_create(&(data->all_done_eating),
									NULL, ft_all_done_eating, data))
	{
		free(data);
		return (ft_error(ERROR_PTHREAD_CREATE));
	}
	return (0);
}

int		ft_delete_data(void)
{
	pthread_mutex_lock(&((*get_data())->block));
	pthread_mutex_unlock(&((*get_data())->block));
	pthread_mutex_destroy(&((*get_data())->block));
	ft_delete_table((*get_data())->table);
	free(*get_data());
	return (0);
}
