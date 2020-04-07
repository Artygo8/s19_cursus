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
		{
			ft_putendl_fd(&(((char*)tmpenv->content)[4]), 1);
			return ;
		}
		tmpenv = tmpenv->next;
	}
	write(1, "\n", 1);
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
			if (tmpvars->content && !ft_strncmp(tmpvars->content, tmpargs->content, size)
				&& ((char*)tmpvars->content)[size] == '=')
				ft_var_to_lst(cmd->env, tmpvars->content);
			tmpvars = tmpvars->next;
		}
		tmpargs = tmpargs->next;
	}
}

void		ft_unset_var(t_cmd *cmd)
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
			if (tmpvars->content && !ft_strncmp(tmpvars->content, tmpargs->content, size)
				&& ((char*)tmpvars->content)[size] == '=')
			{
				free(tmpvars->content);
				tmpvars->content = NULL;
			}
			tmpvars = tmpvars->next;
		}
		tmpargs = tmpargs->next;
	}
}

void		ft_unset(t_cmd *cmd)
{
	t_list			*tmpenv;
	t_list			*tmpargs;
	unsigned int	size;

	tmpargs = cmd->args;
	while (tmpargs)
	{
		size = ft_strlen((char*)tmpargs->content);
		tmpenv = cmd->env;
		while (tmpenv)
		{
			if (tmpenv->content && !ft_strncmp(tmpenv->content, tmpargs->content, size)
				&& ((char*)tmpenv->content)[size] == '=')
			{
				free(tmpenv->content);
				tmpenv->content = NULL;
			}
			tmpenv = tmpenv->next;
		}
		tmpargs = tmpargs->next;
	}
	ft_unset_var(cmd);
}


void	put_cmd(t_cmd *cmd)
{
	t_list *args_cpy = cmd->args;
	t_list *vars_cpy = cmd->vars;

	printf("\nSIZEOF struct = %ld\n", sizeof(t_cmd));
	printf("line = %s\n", (char*)cmd->line);
	printf("pos = %d\n", cmd->i);
	printf("cmd = %d\n", cmd->cmd);
	printf("args :\n");
	while (args_cpy)
	{
		printf("- %s\n", (char*)args_cpy->content);
		args_cpy = args_cpy->next;
	}
	if (cmd->env)
		printf("2nd env line = %s\n", (char*)cmd->env->next->content);
	printf("vars :\n");
	while (vars_cpy)
	{
		printf("-%s\n", (char*)vars_cpy->content);
		vars_cpy = vars_cpy->next;
	}
	printf("fd_output = %d\n", cmd->fd_output);
	printf("fd_append = %d\n", cmd->fd_append);
	printf("fd_input = %d\n", cmd->fd_input);
	printf("exit status = %d\n\n", cmd->exit_status);
}

void	ft_reset_cmd(t_cmd *cmd)
{
	char	*tmp;

	free(cmd->line);
	cmd->line = NULL;
	cmd->i = 0;
	cmd->cmd = 0;
	ft_lstclear(&(cmd->args), free);
	cmd->args = NULL;
	cmd->fd_output = 1;
	cmd->fd_append = 0;
	cmd->fd_input = 0;
	tmp = ft_itoa(cmd->exit_status);
	ft_var_to_lst(cmd->vars, ft_strjoin("?=", tmp));
	free(tmp);
	cmd->exit_status = 0;
	free(cmd->error);
	cmd->error = NULL;
}// + remove any TMPFILES caused by pipes
