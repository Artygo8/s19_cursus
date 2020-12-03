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

int		ft_set_data()
{
	if (!(*get_data() = (t_data *)malloc(sizeof(t_data))))
		return (ft_error(ERROR_MALLOC_FAIL));
	if (pthread_mutex_init(&((*get_data())->no_dead_lock), NULL)
	|| pthread_mutex_init(&((*get_data())->write_lock), NULL)
	|| pthread_mutex_init(&((*get_data())->binary_lock[0]), NULL)
	|| pthread_mutex_init(&((*get_data())->binary_lock[1]), NULL)
	|| !((*get_data())->table = ft_table_dup()))
	{
		free(*get_data());
		return (ERROR);
	}
	return (0);
}

int		ft_delete_data()
{
	ft_delete_table((*get_data())->table);
	if (pthread_mutex_destroy(&((*get_data())->no_dead_lock))
	|| pthread_mutex_destroy(&((*get_data())->write_lock))
	|| pthread_mutex_destroy(&((*get_data())->binary_lock[0]))
	|| pthread_mutex_destroy(&((*get_data())->binary_lock[1])))
	{
		free(*get_data());
		return (ft_error(ERROR_MUTEX_DESTROY));
	}
	free(*get_data());
	return (0);
}
