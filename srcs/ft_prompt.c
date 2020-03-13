#include "minishell.h"

int		ft_prompt(char *name)
{
	char	*cmd;

	ft_printf("%s $ ", name);
	while (get_next_entry(&cmd))
	{
		ft_printf("given entry --> %s\n", cmd);
		ft_printf("%s $ ", name);
	}
	return (0);
}
