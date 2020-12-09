/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:51:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:51:40 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_put_action(size_t id, int e_action)
{
	sem_wait((*get_data())->write);
	if ((*get_data())->one_dead)
	{
		sem_post((*get_data())->write);
		return (0);
	}
	ft_put_abs_time();
	write(1, " ", 1);
	ft_putunbr(id);
	if (e_action == FORKING)
		ft_putstr_fd(" has taken fork\n", STDOUT_FILENO);
	if (e_action == EATING)
		ft_putstr_fd(" is eating\n", STDOUT_FILENO);
	if (e_action == SLEEPING)
		ft_putstr_fd(" is sleeping\n", STDOUT_FILENO);
	if (e_action == THINKING)
		ft_putstr_fd(" is thinking\n", STDOUT_FILENO);
	if (e_action == DYING)
	{
		ft_putstr_fd(" died\n", STDOUT_FILENO);
		sem_post((*get_data())->dead);
		usleep(100);
	}
	sem_post((*get_data())->write);
	return (0);
}
