#include "minishell.h"

void		ft_echo(t_cmd *cmd, int fd)
{
	int		test;
	t_list	*args_cpy;

	test = 0;
	args_cpy = cmd->args;
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

void		ft_cd(t_cmd *cmd, int res) // res is used to save 2 lines
{
	char	*pwd;
	char	*home;
	char	s[100];

	getcwd(s, 100);
	pwd = ft_strjoin("OLDPWD=", s);
	if (!(cmd->args) || (cmd->args && ((char*)cmd->args->content)[0] == '~'))
	{
		home = ft_vardup("HOME", cmd->env, 4);
		chdir(home);
		free(home);
		if (cmd->args && chdir(&((char*)cmd->args->content)[2]) != 0)
			res = 1;
	}
	else if(chdir(cmd->args->content) != 0)
		res = 1;
	if (res == 1)
	{
		chdir(s);
		cmd->error = ft_strjoin("cd: ",cmd->args->content);
		cmd->exit_status = errno;
		ft_var_to_lst(cmd->env, pwd);
	}
	free(pwd);
}

void		ft_pwd(t_cmd *cmd, int fd)
{
	t_list	*tmpenv;

	tmpenv = cmd->env;
	while (tmpenv)
	{
		if (tmpenv->content && !ft_strncmp(tmpenv->content, "PWD=", 4))
			return ft_putendl_fd(&(((char*)tmpenv->content)[4]), fd);
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
		if (ft_isvar(tmpargs->content)) //ads to the env if necessary
			ft_get_var(cmd);
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
