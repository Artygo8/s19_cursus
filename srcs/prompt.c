#include "minishell.h"

// void	put_cmd(t_cmd *cmd)
// {
// 	ft_printf("cmd = %d\n", cmd->cmd);
// 	ft_printf("arg = %s\n", cmd->arg);
// 	ft_printf("string = %d\n", cmd->string);
// 	ft_printf("option = %d\n", cmd->option);
// 	ft_printf("fd_output = %d\n", cmd->fd_output);
// 	ft_printf("fd_append = %d\n", cmd->fd_append);
// 	ft_printf("fd_input = %d\n", cmd->fd_input);
// }
//
// int		ms_error(int err, char *arg)
// {
// 	ft_putstr_fd("-minishell: ", 2);
// 	if (err == MALLOC)
// 		ft_putendl_fd("malloc failure", 2);
// 	if (err == CMD_NOT_FOUND)
// 	{
// 		ft_putstr_fd(arg, 2);
// 		ft_putendl_fd(": command not found", 2);
// 	}
// 	return (-1);
// }
//
// int		ms_echo(t_cmd *cmd)
// {
// 	if (cmd->option)
// 		ft_putstr_fd(cmd->arg, cmd->fd_output);
// 	else
// 		ft_putendl_fd(cmd->arg, cmd->fd_output);
// 	return (0);
// }
//
// int		ms_apply_cmd(t_cmd *cmd)
// {
// 	if (cmd->cmd == 0)
// 		return (0);
// 	if (cmd->cmd == -1)
// 		ms_error(CMD_NOT_FOUND, cmd->arg);
// 	if (cmd->cmd == ECHO)
// 		ms_echo(cmd);
// 	return (0);
// }
//
// /*
// ** ms_parsing gets one command at a time, pipe management will be done later.
// */
//
// int		ms_parsing(t_cmd *cmd, char *line, int i) //this function should return the number of char processed for the multi cmd
// {
// //	printf("parsing : %s\n", line);
// //	put_cmd(cmd);
// 	while (ft_isspace(line[i]))
// 		i++;
// //	printf("Now we have : %s\n", &line[i]);
// 	if (cmd->cmd == -1)
// 		return (0);
// 	if (line[i] == '\0')
// 		return (i);
// 	if (cmd->string)
// 		i += ms_get_arg(cmd, &line[i]);
// 	else if (line[i] == '>' && line[i + 1] == '>')
// 		i += ms_get_fd(cmd, &line[i + 2], SAVE_OUT); // ne pas oublier de faire +2 pour le resultat de la fonction
// 	else if (line[i] == '>')					// il faut aussi une solution pour raise les erreurs
// 		i += ms_get_fd(cmd, &line[i + 1], APPEND_OUT); // ne pas oublier de faire +1 pour le resultat de la fonction
// 	else if (line[i] == '<')
// 		i += ms_get_fd(cmd, &line[i + 1], FILE_INPUT);
// 	else if (cmd->cmd == 0)
// 		i += ms_get_cmd(cmd, &line[i]);
// 	else if (line[i] == ';')
// 		return (i);
// 	else
// 		i += ms_get_arg(cmd, &line[i]);
// //	printf("just parsed %d char\n", i);
// 	ms_parsing(cmd, line, i);
// }
//
// /*
// ** The ideal would be that my ms_cmd_line function takes care of multi cmds.
// ** Maybe as recursive...
// */
//
// int		ms_cmd_line(t_cmd *cmd, char *line)
// {
// 	int		i;
//
// 	i = ms_parsing(cmd, line, 0);	// this function should be returning the number of char processed
// 	if (i == -1)
// 		return (-1);
// 	if (cmd->string)
// 		cmd->arg = ft_strjoin_amount(cmd->arg, "\n", 1);
// 	if (cmd->string || cmd->cmd == 0)
// 		return (0);
// 	ms_apply_cmd(cmd);
// 	if (cmd->cmd == -1)
// 		return (0);
// 	ms_reset_cmd(cmd);
// 	ms_cmd_line(cmd, &line[i]);
// }

void	ft_parsing_cmd(t_cmd *cmd)
{
	while (ft_isspace(cmd->line[cmd->i]))
		cmd->i++;
	if (cmd->exit_status != 0 || cmd->line[cmd->i] == '\0')
		return (apply_cmd(cmd));
	else if (cmd->line[cmd->i] == ';')
		apply_cmd(cmd);
	else if (cmd->line[cmd->i] == '|')
	{
		ft_get_topipe(cmd);
		apply_cmd(cmd);
		ft_get_frompipe(cmd);
	}
	else if (ft_ispath(&(cmd->line[cmd->i])))
		ft_get_exe(cmd);
	else if (ft_isvar(&(cmd->line[cmd->i])))
		ft_get_var(cmd);
	else if (cmd->line[cmd->i] == '<' || cmd->line[cmd->i] == '>')
		ft_get_redir(cmd);
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
//		ms_cmd_line(cmd);
//		put_cmd(cmd);
		ft_parsing_cmd(cmd);
		ft_putstr_fd(name, 1);
		if (cmd->cmd == EXIT)
			break ;
		ft_reset_cmd(cmd);
	}
	ft_reset_cmd(cmd);
	return (0);
}

// c'est au moment ou on set le cmd = ERROR qu'on doit spécifier l'erreur.
// ainsi ça nous permet de continuer à lire tout en étant pas pollué.
// quoiqu'on peut le mettre au exit status...? oui on va faire ça. donc on
// ajoute le status précédent aux variables.
