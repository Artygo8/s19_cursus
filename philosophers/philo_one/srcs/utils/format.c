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

void	ft_put_action(int id, int e_action)
{
	pthread_mutex_lock(ft_get_mutex(WRITE));
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
		return ;
	}
	pthread_mutex_unlock(ft_get_mutex(WRITE));
}
