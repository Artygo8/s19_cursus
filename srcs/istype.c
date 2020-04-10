/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:29:58 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/09 16:46:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isvar_call(t_cmd *cmd)
{
	int i;

	i = cmd->i;
	if (cmd->line[i - 1] == '\\' || ft_isspace(cmd->line[i + 1])
		|| !(cmd->line[i + 1]))
		return (0);
	if (!ft_strncmp(&(cmd->line[cmd->i]), "${}", 3))
	{
		cmd->exit_status = BAD_SUBSTITUTION;
		return (0);
	}
	if (!ft_strncmp(&(cmd->line[cmd->i]), "${", 2))
	{
		i += 2;
		while (ft_isalnum(cmd->line[i]))
			i++;
		if (cmd->line[i] != '}')
		{
			cmd->exit_status = BAD_SUBSTITUTION;
			return (0);
		}
	}
	return (1);
}

int		ft_ispath(char *line)
{
	while (*line && !ft_isspace(*line))
	{
		if (*line++ == '/')
			return (1);
	}
	return (0);
}

int		ft_isvar(char *line)
{
	while (ft_isalnum(*line))
		line++;
	if (*line == '=')
		return (1);
	return (0);
}
