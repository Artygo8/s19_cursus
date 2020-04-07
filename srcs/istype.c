#include "minishell.h"

int		ft_ispath(char *line)
{
	while (*line && !ft_isspace(*line))
	{
		if (*line++  == '/')
			return (1);
	}
	return (0);
}

int		ft_isvar(char *line)
{
	while (ft_isalnum(*line))
		line++;
	if (*line == '=')
		return(1);
	return (0);
}
