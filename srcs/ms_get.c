#include "minishell.h"

/*
char	*ms_get_line_path(char *line)
{
	char	*path;
	int		start;
	int		end;

	start = 0;
	while (ft_isspace(line[start]))
		start++;
	end = start;
	if (line[end] == '\'')
	{
		while (line[end] != '\'' && line[end])
			end++;
	}
	else if (line[end] == '\"')
	{
		while (line[end] != '\"' && line[end])
			end++;
	}
	return (ft_substr(line, start, end - start));
}
*/

/*
** 3 fd_types possible : SAVE_OUT, APPEND_OUT, FILE_INPUT.
*/

int		ms_get_fd(t_cmd *cmd, char *line, int fd_type)
{
	char	*path;
	int		i;

	path = ms_get_line_path(line);
	if (fd_type == SAVE_OUT)
		cmd->fd_output = open(path, O_CREAT | O_WRONLY | O_APPEND, 644);
	else if (fd_type == APPEND_OUT)
		cmd->fd_append = open(path, O_CREAT | O_WRONLY | O_TRUNC, 644);
	else if (fd_type == FILE_INPUT)
		cmd->fd_input = open(path, O_RDONLY);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	i += ft_strlen(path);
	free(path);
	return (i);
}

int		ms_get_str(t_cmd *cmd, char *line)
{
	int size;

	size = 1; //first element was already approved
	if (cmd->string == 0)
		while (line[size] && !ft_isspace(line[size]) && line[size] != 39 && line[size] != 34)
			size++;
	else if (cmd->string == 1)
		while (line[size] && (line[size] != 39 || line[size - 1] == 92))
			size++;
	else if (cmd->string == 2)
		while (line[size] && (line[size] != 34 || line[size - 1] == 92))
			size++;
	cmd->arg = ft_strjoin_amount(cmd->arg, line, size);
	return (size);
}

int		ms_get_arg(t_cmd *cmd, char *line)
{
	int size;

	size = 1;
	if (*line == 39 && cmd->string == 0) // 39 is '
		cmd->string = 1;
	else if (*line == 34 && cmd->string == 0) //34 is "
		cmd->string = 2;
	else if (*line == 39 && cmd->string == 1) // 39 is '
		cmd->string = 0;
	else if (*line == 34 && cmd->string == 2) //34 is "
		cmd->string = 0;
	else
		size = ms_get_str(cmd, line);
	return (size);
}

int		ms_get_cmd(t_cmd *cmd, char *line)
{
	int i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	if (!(ft_strncmp(line, "cd", 2)) && ft_isspace(line[2]))
		cmd->cmd = CD;
	else if (!(ft_strncmp(line, "pwd", 3)) && ft_isspace(line[3]))
		cmd->cmd = PWD;
	else if (!(ft_strncmp(line, "echo", 4)) && ft_isspace(line[4]))
		cmd->cmd = ECHO;
	else
	{
		cmd->cmd = ERROR;
		ms_get_str(cmd, line);
	}
	return (i);
}
