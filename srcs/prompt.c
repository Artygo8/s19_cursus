/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:30:14 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/09 17:09:42 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset_cmd(t_cmd *cmd)
{
	char	*tmp;
	char	s[100];

	cmd->cmd = 0;
	ft_lstclear(&(cmd->args), free);
	cmd->args = NULL;
	if (cmd->fd_output != 0 && cmd->fd_output != 1)
		close(cmd->fd_output);
	cmd->fd_output = 1;
	if (cmd->fd_append != 0 && cmd->fd_append != 1)
		close(cmd->fd_append);
	cmd->fd_append = 0;
	if (cmd->fd_input != 0 && cmd->fd_input != 1)
		close(cmd->fd_input);
	cmd->fd_input = 0;
	tmp = ft_itoa(cmd->exit_status);
	ft_var_to_lst(cmd->vars, ft_strjoin("?=", tmp));
	free(tmp);
	cmd->exit_status = 0;
	free(cmd->error);
	cmd->error = NULL;
	getcwd(s, 100);
	tmp = ft_strjoin("PWD=", s);
	ft_var_to_lst(cmd->env, tmp);
	free(tmp);
}

void	ft_puterror(t_cmd *cmd)
{
	ft_putstr_fd(cmd->error, 2);
	ft_putstr_fd(": ", 2);
	if (cmd->exit_status == BAD_SUBSTITUTION)
		ft_putendl_fd("bad substition", 2);
	else if (cmd->exit_status == COMMAND_NOT_FOUND)
		ft_putendl_fd("command not found", 2);
	else
		ft_putendl_fd(strerror(cmd->exit_status), 2);
}

void	apply_cmd(t_cmd *cmd)
{
	int		fd;

	fd = (cmd->fd_output) ? cmd->fd_output : cmd->fd_append;
	if (!cmd->exit_status)
	{
		// if (cmd->cmd == MSH)
		// 	ft_msh(cmd);
		if (cmd->cmd == ECHO || cmd->cmd == ECHON)
			ft_echo(cmd, fd);
		else if (cmd->cmd == CD)
			ft_cd(cmd, 0);
		else if (cmd->cmd == ENV)
			ft_putenv(cmd->env, fd);
		else if (cmd->cmd == PWD)
			ft_pwd(cmd, fd);
		else if (cmd->cmd == EXPORT)
			ft_export(cmd);
		else if (cmd->cmd == UNSET)
			ft_unset(cmd);
		else if (cmd->cmd == EXIT)
			return ;
	}
	if (cmd->exit_status)
		ft_puterror(cmd);
	ft_reset_cmd(cmd);
}

void	ft_parsing_cmd(t_cmd *cmd)
{
	while (ft_isspace(cmd->line[cmd->i]))
		cmd->i++;
	if (cmd->line[cmd->i] == '\0' || cmd->cmd == EXIT)
		return (apply_cmd(cmd));
	else if (cmd->line[cmd->i] == ';' && cmd->i++)
		apply_cmd(cmd);
	// else if (cmd->line[cmd->i] == '|')
	// {
	// 	ft_get_topipe(cmd);
	// 	apply_cmd(cmd);
	// 	ft_get_frompipe(cmd);
	// }
	else if (cmd->cmd == 0 && ft_ispath(&(cmd->line[cmd->i])))
		ft_get_exe(cmd);
	else if (cmd->cmd == 0 && ft_isvar(&(cmd->line[cmd->i])))
		ft_get_var(cmd);
	else if (cmd->line[cmd->i] == '<' || cmd->line[cmd->i] == '>')
		ft_get_redir(cmd);
	else if (cmd->cmd == 0)
		ft_get_cmd(cmd);
	else
		ft_get_arg(cmd);
	ft_parsing_cmd(cmd);
}

int		ft_prompt(char *name, t_cmd *cmd)
{
	ft_pwd(cmd, 1);
	ft_putstr_fd(name, 1);
	while (get_next_line(0, &(cmd->line)))
	{
		ft_parsing_cmd(cmd);
		// write(1, "\n", 1);
		if (cmd->cmd == EXIT)
			break ;
		ft_pwd(cmd, 1);
		ft_putstr_fd(name, 1);
		free(cmd->line);
		cmd->line = NULL;
		cmd->i = 0;
	}
	ft_reset_cmd(cmd);
	return (0);
}
