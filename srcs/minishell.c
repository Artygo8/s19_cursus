#include "minishell.h"

int main(int argc, char const *argv[], char **envp)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (12);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->env = (t_list *)ft_lstenv(envp);
	cmd->fd_output = 1;
//	ms_prompt("prompt", &cmd);
	ft_var_to_env(cmd->env, "HEY=SHITHOLE");
	ft_putenv(cmd->env);
	return (0);
}
