#include "minishell.h"

void	ft_reset_cmd(t_cmd *cmd)
{
	char	*tmp;

	free(cmd->line);
	cmd->line = NULL;
	cmd->i = 0;
	cmd->cmd = 0;
	ft_lstclear(&(cmd->args), free);
	cmd->args = NULL;
	cmd->fd_output = 1;
	cmd->fd_append = 0;
	cmd->fd_input = 0;
	tmp = ft_itoa(cmd->exit_status);
	ft_var_to_lst(cmd->vars, ft_strjoin("?=", tmp));
	free(tmp);
	cmd->exit_status = 0;
	free(cmd->error);
	cmd->error = NULL;
}// + remove any TMPFILES caused by pipes

void ft_puterror(t_cmd *cmd)
{
	ft_putstr_fd(cmd->error, 2);
	ft_putstr_fd(": ", 2);
	if (cmd->exit_status == BAD_SUBSTITUTION)
		ft_putendl_fd("bad substition", 2);
	else if (cmd->exit_status == COMMAND_NOT_FOUND)
		ft_putendl_fd("command not found", 2);
	else
		ft_putendl_fd(strerror(cmd->exit_status), 2);
}

void apply_cmd(t_cmd *cmd)
{
	if (!cmd->exit_status)
	{
		// else if (cmd->cmd == MSH)
		// 	ft_msh(cmd);
		if (cmd->cmd == ECHO || cmd->cmd == ECHON)
			ft_echo(cmd);
		else if (cmd->cmd == CD)
			ft_cd(cmd);
		else if (cmd->cmd == ENV)
			ft_putenv(cmd->env);
		else if (cmd->cmd == PWD)
			ft_pwd(cmd);
		else if (cmd->cmd == EXPORT)
			ft_export(cmd);
		else if (cmd->cmd == UNSET)
			ft_unset(cmd);
		else if (cmd->cmd == EXIT)
			return ;
	}
	if (cmd->exit_status)
		ft_puterror(cmd);
	ft_reset_cmd(cmd);
}

void	ft_parsing_cmd(t_cmd *cmd)
{
	while (ft_isspace(cmd->line[cmd->i]))
		cmd->i++;
	if (cmd->line[cmd->i] == '\0' || cmd->cmd == EXIT)
		return (apply_cmd(cmd));
	else if (cmd->line[cmd->i] == ';')
		apply_cmd(cmd);
	// else if (cmd->line[cmd->i] == '|')
	// {
	// 	ft_get_topipe(cmd);
	// 	apply_cmd(cmd);
	// 	ft_get_frompipe(cmd);
	// }
	else if (ft_ispath(&(cmd->line[cmd->i])))
		ft_get_exe(cmd);
	else if (cmd->cmd == 0 && ft_isvar(&(cmd->line[cmd->i])))
		ft_get_var(cmd);
	// else if (cmd->line[cmd->i] == '<' || cmd->line[cmd->i] == '>')
	// 	ft_get_redir(cmd); // only ONE redir, so the other must be deleted
	else if (cmd->cmd == 0)
		ft_get_cmd(cmd);
	else
		ft_get_arg(cmd);
	ft_parsing_cmd(cmd);
}

int		ft_prompt(char *name, t_cmd *cmd)
{
	ft_putstr_fd(name, 1);
	while (get_next_line(0, &(cmd->line)))
	{
		ft_parsing_cmd(cmd);
		if (cmd->cmd == EXIT)
			break ;
		ft_putstr_fd(name, 1);
		ft_reset_cmd(cmd);
	}
	ft_reset_cmd(cmd);
	return (0);
}
