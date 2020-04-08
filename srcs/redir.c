#include "minishell.h"

void	ft_get_append(t_cmd *cmd)
{
	int		tmp;
	char	*path;

	cmd->i += 1;
	printf("SHOULD APPEND\n");
	path = ft_minidup(cmd);
	if (!(tmp = open(path, O_CREAT | O_WRONLY | O_APPEND, 0b0110100100)))
	{
		cmd->error = path;
		cmd->exit_status = errno;
	}
	else
	{
		if (cmd->fd_output != 1 && cmd->fd_output != 0 && cmd->fd_output != tmp)
			close(cmd->fd_output);
		cmd->fd_output = 0;
		if (cmd->fd_append != 0)
			close(cmd->fd_append);
		cmd->fd_append = tmp;
	}
}

void	ft_get_output(t_cmd *cmd)
{
	int		tmp;
	char	*path;

	cmd->i += 1;
	path = ft_minidup(cmd);
	if (!(tmp = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0b0110100100)))
	{
		cmd->error = path;
		cmd->exit_status = errno;
	}
	else
	{
		if (cmd->fd_output != 1 && cmd->fd_output != 0)
			close(cmd->fd_output);
		if (cmd->fd_append != 0)
		{
			close(cmd->fd_append);
			cmd->fd_append = 0;
		}
		cmd->fd_output = tmp;
	}
}

void	ft_get_input(t_cmd *cmd)
{
	char	*path;

	cmd->i += 1;
	path = ft_minidup(cmd);
	if (!(cmd->fd_input = open(path, O_RDONLY)))
	{
		cmd->error = path;
		cmd->exit_status = errno;
	}
}

void	ft_get_redir(t_cmd *cmd)
{
	if (cmd->line[cmd->i] == '>' && cmd->line[cmd->i + 1] == '>')
		ft_get_append(cmd);
	else if (cmd->line[cmd->i] == '>')
		ft_get_output(cmd);
	else if (cmd->line[cmd->i] == '<')
		ft_get_input(cmd);
}
