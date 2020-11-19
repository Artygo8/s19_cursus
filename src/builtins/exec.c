/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../src/builtins/exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:58:21 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/21 10:58:21 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_trypath(char *name)
{
	int		i;
	char	*path;
	char	**sp;

	path = ft_vardup_from_env("PATH");
	if (!(i = 0) && path && (!path[0] || ((path[0] == ':'
				|| path[ft_strlen(path) - 1] == ':') && ft_file_exists(name))))
	{
		free(path);
		return (ft_strdup(name));
	}
	sp = ft_split(path, ':');
	free(path);
	while (sp && sp[i])
	{
		path = fts_strjoinfree(fts_strdup(sp[i++]), fts_strjoin("/", name));
		if (ft_file_exists(path))
		{
			ft_free_table(sp);
			return (path);
		}
		free(path);
	}
	ft_free_table(sp);
	return (NULL);
}

char	*ft_get_path(char *path)
{
	char	*new;

	if (ft_ispath(path))
	{
		if (!ft_file_exists(path))
			ft_puterror(path, NO_SUCH);
		else if (ft_file_directory(path))
			ft_puterror(path, IS_DIR);
		else if (!ft_file_permitted(path) || !ft_file_readable(path))
			ft_puterror(path, PERMISSION_DENIED);
		return (fts_strdup(path));
	}
	else if ((new = ft_trypath(path)))
	{
		if (!ft_file_exists(new))
			ft_puterror(new, NO_SUCH);
		else if (ft_file_directory(new))
			ft_puterror(new, IS_DIR);
		else if (!ft_file_permitted(new))
			ft_puterror(new, PERMISSION_DENIED);
	}
	else
		ft_puterror(path, COMMAND_NOT_FOUND);
	return (new);
}

void	ft_execve(t_cmd *cmd, char *path)
{
	char	**table_tok;
	char	**table_env;
	int		status;
	pid_t	pid;

	table_tok = ft_lsttotable(cmd->tokens);
	table_env = ft_lsttotable(*ft_get_env());
	if ((pid = fork()) == -1)
		return (ft_puterror("pid", PID_ERROR));
	if (pid > 0)
	{
		waitpid(pid, &(status), 0);
		if (status == SIGINT || status == SIGQUIT)
			ft_set_status(status + 128);
		else
			ft_set_status(status / 256);
	}
	else
	{
		ft_set_child_process(TRUE);
		execve(path, table_tok, table_env);
	}
	ft_free_table(table_tok);
	ft_free_table(table_env);
}

void	ft_exec(t_cmd *cmd)
{
	char	*path;

	path = ft_get_path(cmd->tokens->content);
	if (*ft_get_status() != 0)
	{
		free(path);
		return ;
	}
	ft_execve(cmd, path);
	free(path);
}
