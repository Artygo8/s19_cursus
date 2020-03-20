#include "minishell.h"

int		ms_error(int err, char *arg)
{
	ft_putstr_fd("-minishell: ", 2);
	if (err == MALLOC)
		ft_putendl_fd("malloc failure", 2);
	if (err == CMD_NOT_FOUND)
	{
		ft_putword_fd(arg, 2);
		ft_putendl_fd(": command not found", 2);
	}
	return (-1);
}

int		ms_echo(char *arg)
{
	ft_putendl_fd(arg, 1);
	return (0);
}

int		ms_apply_cmd(int cmd, char *arg)
{
	if (cmd == 0)
		return (0);
	if (cmd == -1)
		ms_error(CMD_NOT_FOUND, arg);
	if (cmd == 1)
		ms_echo(arg);
	free(arg);
	arg = NULL;
	return (0);
}

int		ms_get_cmd(char *line, int *cmd)
{
	int i;

	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (0);
	if (ft_strncmp("echo", *line, 4) && ft_isspace((*line)[4]))
		return (1);
	return (i);
}

int		ms_get_status(char *line, int busy)
{
	int		status;
	int		pos;

	status = 0;
	pos = ft_strchr_pos(line, '\'');
	if (pos != -1 && (ft_strchr_pos(&line[pos + 1], '\'') != -1))
		status = 1;
	pos = ft_strchr_pos(line, '\"');
	if (pos != -1 && (ft_strchr_pos(&line[pos + 1], '\"') != -1))
		status = 3;
	printf("busy = %d\n", status ^ busy);
	return (status ^ busy);
}

// i want to be able to do multiline, so i use static until im done

int		ms_cmd_line(char *line, int busy)
{
	static int	cmd;
	static char	*arg;
	int			i;

	i = 0;
	if (!busy)
		cmd = ms_get_cmd(line);
	arg = ft_strjoin_buf(arg, line);
	busy = ms_get_status(line, busy); //busy rendu en fonction de la présence de ', ", &&, |, ... qui puisse causer du multiligne
	if (busy == 0)
	{
		ms_apply_cmd(cmd, arg);
		free(arg);
		arg = NULL;
	}
	return (busy);
}

/*
** I use cmd (command number) as a return to verify if i am
** still inside a command. (for example in a multiline echo)
*/

int		ms_prompt(char *name)
{
	t_cmd		*cmd;
	char		*line;

	if (!(cmd = (t_cmd)malloc(sizeof(t_cmd))))
		return (ms_error(MALLOC));
	ft_printf("%s $ ", name);
	while (get_next_entry(&line))
	{
		busy = ms_cmd_line(line, busy);
		if (busy)
			ft_printf("> ");
		else
			ft_printf("%s $ ", name);
		free(line);
	}
	free(line);
	return (0);
}
