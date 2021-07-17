/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		ft_id_builtin(char *name)
{
	if (!ft_strcmp(name, "echo"))
		return (ECHO);
	if (!ft_strcmp(name, "cd"))
		return (CD);
	if (!ft_strcmp(name, "pwd"))
		return (PWD);
	if (!ft_strcmp(name, "export"))
		return (EXPORT);
	if (!ft_strcmp(name, "unset"))
		return (UNSET);
	if (!ft_strcmp(name, "env"))
		return (ENV);
	if (!ft_strcmp(name, "exit"))
		return (EXIT);
	return (FALSE);
}

void	ft_builtin(t_cmd *cmd, int id)
{
	if (id == ECHO)
		ft_echo(cmd->tokens->next, cmd->fd_out);
	if (id == CD)
		ft_cd(cmd->tokens->next);
	if (id == UNSET)
		ft_unset(cmd->tokens->next);
	if (id == PWD)
		ft_pwd(cmd->fd_out);
	if (id == EXIT)
		ft_exit(cmd->tokens->next);
	if (id == ENV)
		ft_putenv_fd(cmd->fd_out);
	if (id == EXPORT)
		ft_export(cmd->tokens->next, cmd->fd_out);
}

void	ft_set_fileno(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
		dup2(cmd->fd_in, STDIN_FILENO);
	else if (cmd->pipe_in)
		dup2(cmd->pipe_in, STDIN_FILENO);
	if (cmd->fd_out > 1)
		dup2(cmd->fd_out, STDOUT_FILENO);
	else if (cmd->pipe_out)
		dup2(cmd->pipe_out, STDOUT_FILENO);
	else
		dup2(1, STDOUT_FILENO);
}

void	ft_parser(t_cmd *cmd)
{
	int		id;
	char	*cmd_name;
	char	*path;

	path = NULL;
	cmd_name = (char*)cmd->tokens->content;
	ft_set_fileno(cmd);
	if (ft_strchr(cmd_name, '/'))
		ft_exec(cmd);
	else if ((id = ft_id_builtin(cmd_name)))
		ft_builtin(cmd, id);
	else if (!(path = ft_vardup_from_env("PATH")))
		ft_puterror(cmd_name, NO_SUCH);
	else
	{
		free(path);
		ft_exec(cmd);
	}
}
