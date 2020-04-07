#include "minishell.h"

void	put_cmd(t_cmd *cmd)
{
	printf("SIZEOF struct = %ld\n", sizeof(t_cmd));
	printf("line = %s\n", (char*)cmd->line);
	printf("pos = %d\n", cmd->cmd);
	printf("cmd = %d\n", cmd->cmd);
	printf("args =\n");
	while (cmd->args)
	{
		printf("	%s\n", (char*)cmd->args->content);
		cmd->args = cmd->args->next;
	}
	if (cmd->env)
		printf("2nd env line = %s\n", (char*)cmd->env->next->content);
	printf("args =\n");
	while (cmd->vars)
	{
		printf("	%s\n", (char*)cmd->vars->content);
		cmd->vars = cmd->vars->next;
	}
	printf("fd_output = %d\n", cmd->fd_output);
	printf("fd_append = %d\n", cmd->fd_append);
	printf("fd_input = %d\n", cmd->fd_input);
	printf("exit status = %d\n", cmd->exit_status);
}

void	ft_reset_cmd(t_cmd *cmd)
{
	char	*tmp;

	free(cmd->line);
	cmd->line = NULL;
	cmd->i = 0;
	free(cmd->args);
	cmd->args = NULL;
	cmd->fd_output = 1;
	cmd->fd_append = 0;
	cmd->fd_input = 0;
	tmp = ft_itoa(cmd->exit_status);
	ft_var_to_lst(cmd->vars, ft_strjoin("?=", tmp));
	free(tmp);
	cmd->exit_status = 0;
}// + remove any TMPFILES caused by pipes
