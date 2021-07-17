/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		*ft_get_signal(void)
{
	static int signal = 0;

	return (&signal);
}

void	ft_set_signal(int new_signal)
{
	int *signal_ptr;

	signal_ptr = ft_get_signal();
	*signal_ptr = new_signal;
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (!*ft_is_child_process())
		{
			kill(0, 0);
			fts_putstr_fd("\n"PROMPT, STDERR_FILENO);
			free((*ft_get_msh())->line);
			(*ft_get_msh())->line = NULL;
		}
		else if (*ft_is_child_process())
			kill(0, 0);
		ft_set_signal(SIGINT);
		ft_set_status(SIGNAL_CTRL_C);
		ft_set_last_status();
	}
	if (sig == SIGQUIT)
	{
		ft_set_signal(SIGQUIT);
		if ((*ft_get_msh())->line && !*ft_is_child_process())
		{
			fts_putstr_fd("Quit\n", STDOUT_FILENO);
			free((*ft_get_msh())->line);
			(*ft_get_msh())->line = NULL;
		}
	}
}
