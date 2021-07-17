/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:37:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/07 15:37:12 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_error(int e_error)
{
	if (e_error == ERROR_NB_ARG)
		ft_putstr_fd("Error: wrong number of arguments.\n", STDERR_FILENO);
	else if (e_error == ERROR_NOT_ULONG)
		ft_putstr_fd("Error: argument not unsigned long.\n", STDERR_FILENO);
	else if (e_error == ERROR_MALLOC_FAIL)
		ft_putstr_fd("Error: malloc fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_PTHREAD_JOIN)
		ft_putstr_fd("Error: pthread_join fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_PTHREAD_CREATE)
		ft_putstr_fd("Error: pthread_create fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_PTHREAD_DETACH)
		ft_putstr_fd("Error: pthread_detach fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_MUTEX_LOCK)
		ft_putstr_fd("Error: MUTEX_LOCK fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_MUTEX_UNLOCK)
		ft_putstr_fd("Error: MUTEX_UNLOCK fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_MUTEX_DESTROY)
		ft_putstr_fd("Error: MUTEX_DESTROY fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_MUTEX_INIT)
		ft_putstr_fd("Error: MUTEX_INIT fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_GTOD)
		ft_putstr_fd("Error: gettimeofday fail.\n", STDERR_FILENO);
	else if (e_error == ERROR_USLEEP)
		ft_putstr_fd("Error: USLEEP fail.\n", STDERR_FILENO);
	return (e_error);
}
