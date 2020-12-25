/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_last_command(t_cmd *cmd, int fd_in)
{
	char	*tmp;
	t_list	*cpy;

	cpy = cmd->tokens;
	while (cpy->next)
		cpy = cpy->next;
	tmp = ft_strjoin("_=", cpy->content);
	ft_assign_to_env(tmp);
	free(tmp);
	dup2(fd_in, STDIN_FILENO);
	dup2(cmd->fd_out, STDOUT_FILENO);
	ft_parser(cmd);
	ft_close(fd_in);
	ft_close(cmd->fd_out);
}

void	ft_parent_command(t_list *pipeline, int pipe_fd[2], pid_t pid)
{
	t_cmd	*cmd;
	int		status;

	cmd = (t_cmd *)pipeline->content;
	ft_close(pipe_fd[1]);
	if (cmd->fd_in)
		ft_pipeline_recursion(pipeline->next, cmd->fd_in);
	else
		ft_pipeline_recursion(pipeline->next, pipe_fd[0]);
	waitpid(pid, &(status), 0);
	if (cmd->end == SEMI)
		ft_set_status(status / 256);
	ft_close(pipe_fd[0]);
}

void	ft_child_command(t_cmd *cmd, int pipe_fd[2], int fd_in)
{
	ft_set_child_process(TRUE);
	dup2(fd_in, STDIN_FILENO);
	ft_close(pipe_fd[0]);
	if (cmd->end == SEMI || cmd->fd_out > 1)
		dup2(cmd->fd_out, STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	ft_parser(cmd);
	ft_close(pipe_fd[1]);
	ft_close(fd_in);
	exit(*ft_get_status());
}

void	ft_pipeline_recursion(t_list *pipeline, int fd_in)
{
	pid_t	pid;
	t_cmd	*cmd;
	int		pipe_fd[2];

	if (pipeline && pipeline->content)
	{
		cmd = (t_cmd *)pipeline->content;
		if (cmd->end == SEMI && fd_in == cmd->fd_in)
			ft_last_command(cmd, fd_in);
		else
		{
			if (pipe(pipe_fd) < 0)
				return (ft_puterror("cannot init pipe", PIPE_ERROR));
			if ((pid = fork()) < 0)
				return (ft_puterror("cannot init pid", PID_ERROR));
			else if (pid > 0)
			{
				ft_close(fd_in);
				ft_parent_command(pipeline, pipe_fd, pid);
			}
			else if (pid == 0)
				ft_child_command(cmd, pipe_fd, fd_in);
		}
	}
}
