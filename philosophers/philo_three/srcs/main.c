/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:42:36 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:42:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char const *argv[])
{
	int				i;
	int				ret;
	t_data			*data;
	static pid_t	pids[300];

	if (argc != 5 && argc != 6)
		return (ft_error(ERROR_NB_ARG));
	if ((ret = set_input(argc, argv)))
		return (ret);
	if ((ret = ft_set_data()))
		return (ret);
	data = *get_data();
	i = 0;
	while (i++ < *get_input(NB_PHILO))
		pids[i - 1] = ft_philo_create(i);
	i = 0;
	while (pids[i])
		waitpid(pids[i++], NULL, 0);
	sem_close(data->dead);
	sem_close(data->write);
	sem_close(data->tickets);
	sem_close(data->forks);
	free(data);
	return (0);
}
