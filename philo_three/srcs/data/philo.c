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

pid_t	ft_philo_create(int id, t_data *data)
{
	t_philo		*new;
	pid_t		pid;

	if (!(new = (t_philo*)malloc(sizeof(t_philo))))
		return (0);
	memset(new, 0, sizeof(t_philo));
	new->id = id;
	new->eat_count = 0;
	new->last_meal = ft_get_ms();
	if ((pid = fork()) == -1)
	{
		ft_error(ERROR);
		return (0);
	}
	else if (pid == 0)
	{
		living(new);
		free(new);
		free(data);
		exit(0);
	}
	free(new);
	return (pid);
}
