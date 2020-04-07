#include "minishell.h"


char*	ft_basicdup(t_cmd *cmd)

char*	ft_weakdup(t_cmd *cmd)

char*	ft_strongdup(t_cmd *cmd)

char*	ft_minidup(t_cmd *cmd)
{
	char *var;
	char *tmp;
	char *tmp2;

	var = NULL;
	while (!ft_isspace(cmd->line[cmd->i]) && cmd->exit_status == 0) // condition d'arrêt ultime
	{
		tmp = var;
		if (cmd->line[cmd->i] == '\'')
			tmp2 = ft_strongdup(cmd);
		if (cmd->line[cmd->i] == '\"')
			tmp2 = ft_weakdup(cmd);
		else
			tmp2 = ft_basicdup(cmd);
		var = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
}
