#include "minishell.h"

ft_get_topipe(t_cmd *cmd)
{

}

ft_get_frompipe(t_cmd *cmd)
{

}

ft_get_exe(t_cmd *cmd)
{

}

void	ft_get_var(t_cmd *cmd) //lets directly add it care about: john3=hello'yes'"${}ha"
{
	int		i;
	char*	var;
	char*	tmp;
	char*	tmp2;

	while (cmd->line[i] != '=')
		i++;
	ft_substr(&(cmd->line[cmd->i]), 0, i + 1);
	cmd->i += i + 1;
	var = ft_minidup(cmd);
	ft_var_to_lst(cmd->vars, var);
	free(var);
}

ft_get_redir(t_cmd *cmd)
{

}

ft_get_cmd(t_cmd *cmd)
{
	char	*command;

	command = ft_minidup(cmd);

}

ft_get_arg(t_cmd *cmd)
{

}
