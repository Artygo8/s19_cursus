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

t_data	*ft_data_dup(t_input *input)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->start_tv = ft_timedup();
	data->input = input;
	pthread_mutex_init(&(data->no_dead_lock), NULL);
	pthread_mutex_init(&(data->write_lock), NULL);
	pthread_mutex_init(&(data->binary_lock[0]), NULL);
	pthread_mutex_init(&(data->binary_lock[1]), NULL);
	data->table = ft_table_dup(input->nb_philo);
	return (data);
}

void	ft_delete_data(t_data *data)
{
	free(data->start_tv);
	pthread_mutex_destroy(&(data->no_dead_lock));
	pthread_mutex_destroy(&(data->write_lock));
	pthread_mutex_destroy(&(data->binary_lock[0]));
	pthread_mutex_destroy(&(data->binary_lock[1]));
	ft_delete_table(data->table);
}
