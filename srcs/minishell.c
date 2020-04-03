#include "minishell.h"

int main(int argc, char const *argv[], char **envp)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (12);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->env = (t_list *)ft_lstenv(envp);
	cmd->fd_output = 1;
	ft_prompt("prompt $", cmd);
//	ft_putenv(cmd->env);
//	put_cmd(cmd);
/*	ft_lstclear(&(cmd->args), free); */
	ft_lstclear(&(cmd->env), free);
	ft_lstclear(&(cmd->vars), free);
	free(cmd);
	return (0);
}
