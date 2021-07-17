/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_list *arg)
{
	int status;

	if (!arg)
		status = 0;
	else if (!ft_is_numeric(arg->content))
	{
		fts_putstr_fd("minishell: exit: ", STDERR_FILENO);
		fts_putstr_fd(arg->content, STDERR_FILENO);
		fts_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		status = NUMERIC_ARGUMENT_REQUIRED;
	}
	else if (arg->next)
	{
		fts_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		status = INVALID_IDENTIFIER;
	}
	else
		status = ft_atoi(arg->content) & 0xff;
	ft_delete_msh();
	free(*ft_get_msh());
	ft_lstclear(ft_get_env(), free);
	free(*ft_get_env());
	exit(status);
}
