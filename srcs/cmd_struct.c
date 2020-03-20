#include "minishell.h"

void	ms_free_childs(t_cmd *cmd)
{
	t_cmd	*tmp;

	cmd = cmd->next;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}

// This function should also close open fd

int		ms_reset_cmd(t_cmd *cmd)
{
	ms_free_childs(cmd);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->fd_output = 1;
}
