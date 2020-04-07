#include "minishell.h"

// ft_get_topipe(t_cmd *cmd)
// {
//
// }
//
// ft_get_frompipe(t_cmd *cmd)
// {
//
// }

void	ft_get_exe(t_cmd *cmd)
{
	cmd->cmd = MSH;
}

void	ft_get_var(t_cmd *cmd) //lets directly add it care about: john3=hello'yes'"${}ha"
{
	int		i;
	char*	var;
	char*	tmp;
	char*	tmp2;

	while (cmd->line[i] && cmd->line[i] != '=')
		i++;
	tmp = ft_substr(&(cmd->line[cmd->i]), 0, i + 1);
	cmd->i += i + 1;
	tmp2 = ft_minidup(cmd);
	var = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	ft_var_to_lst(cmd->vars, var);
	free(var);
}

// ft_get_redir(t_cmd *cmd)
// {
//
// }

void	ft_get_echo(t_cmd *cmd)
{
	cmd->cmd = ECHO;
	while (cmd->line[cmd->i] && ft_isspace(cmd->line[cmd->i]))
		cmd->i++;
	if (!ft_strncmp(&(cmd->line[cmd->i]), "-n", 2) && ft_isspace(cmd->line[cmd->i + 2]))
	{
		cmd->cmd = ECHON;
		cmd->i += 2;
	}
}

void	ft_get_cmd(t_cmd *cmd)
{
	char	*command;

	command = ft_minidup(cmd);
	if (!ft_strncmp(command, "msh", 4))
		cmd->cmd = MSH;
	else if (!ft_strncmp(command, "echo", 5)) //dont forget -n
		ft_get_echo(cmd);
	else if (!ft_strncmp(command, "cd", 3))
		cmd->cmd = CD;
	else if (!ft_strncmp(command, "env", 4))
		cmd->cmd = ENV;
	else if (!ft_strncmp(command, "pwd", 4))
		cmd->cmd = PWD;
	else if (!ft_strncmp(command, "export", 7))
		cmd->cmd = EXPORT;
	else if (!ft_strncmp(command, "unset", 6))
		cmd->cmd = UNSET;
	else if (!ft_strncmp(command, "exit", 5))
		cmd->cmd = EXIT;
	else if (!cmd->exit_status)
	{
		cmd->cmd = ERROR;
		cmd->exit_status = COMMAND_NOT_FOUND;
		cmd->error = ft_strdup(command);
	}
	free(command);
}

void	ft_get_arg(t_cmd *cmd)
{
	char *var;

	var = ft_minidup(cmd);
	ft_lstadd_back(&(cmd->args), ft_lstnew((void*)ft_strdup(var)));
	free(var);
}
