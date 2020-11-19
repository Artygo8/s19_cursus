/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		*ft_get_status(void)
{
	static int status = 0;

	return (&status);
}

int		*ft_get_last_status(void)
{
	static int last_status = 0;

	return (&last_status);
}

void	ft_set_status(int new_status)
{
	int *status_ptr;

	status_ptr = ft_get_status();
	*status_ptr = new_status;
}

void	ft_set_last_status(void)
{
	int *last_status_ptr;

	last_status_ptr = ft_get_last_status();
	*last_status_ptr = *ft_get_status();
}
