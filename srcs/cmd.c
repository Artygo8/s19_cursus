#include "minishell.h"

void		ft_echo(t_cmd *cmd)
{
	int		fd;
	int		test;
	t_list	*args_cpy;

	test = 0;
	args_cpy = cmd->args;
	fd = cmd->fd_output;
	if (cmd->fd_append)
		fd = cmd->fd_append;
	while (args_cpy)
	{
		if (test)
			write(fd, " ", 1);
		test = 1;
		ft_putstr_fd(args_cpy->content, fd);
		args_cpy = args_cpy->next;
	}
	if (cmd->cmd == ECHO)
		write(fd, "\n", 1);
}

void		ft_pwd(t_cmd *cmd)
{
	t_list	*tmpenv;

	tmpenv = cmd->env;
	while (tmpenv)
	{
		if (tmpenv->content && !ft_strncmp(tmpenv->content, "PWD=", 4))
			return ft_putendl_fd(&(((char*)tmpenv->content)[4]), 1);
		tmpenv = tmpenv->next;
	}
}

void		ft_export(t_cmd *cmd)
{
	t_list			*tmpvars;
	t_list			*tmpargs;
	unsigned int	size;

	tmpargs = cmd->args;
	while (tmpargs)
	{
		size = ft_strlen((char*)tmpargs->content);
		tmpvars = cmd->vars;
		while (tmpvars)
		{
			if (tmpvars->content && !ft_strncmp(tmpvars->content,
				tmpargs->content, size)
				&& ((char*)tmpvars->content)[size] == '=')
				ft_var_to_lst(cmd->env, tmpvars->content);
			tmpvars = tmpvars->next;
		}
		tmpargs = tmpargs->next;
	}
}

void		ft_unset_from(t_list *list, t_cmd *cmd)
{
	t_list			*args;
	unsigned int	size;

	args = cmd->args;
	while (args)
	{
		size = ft_strlen((char*)args->content);
		while (list)
		{
			if (list->content && !ft_strncmp(list->content, args->content, size)
				&& ((char*)list->content)[size] == '=')
			{
				free(list->content);
				list->content = NULL;
			}
			list = list->next;
		}
		args = args->next;
	}
}

void		ft_unset(t_cmd *cmd)
{
	ft_unset_from(cmd->vars, cmd);
	ft_unset_from(cmd->env, cmd);
}
