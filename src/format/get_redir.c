/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:30:24 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/09 16:30:26 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_puterror_redir(char *name, int status)
{
	ft_puterror(name, status);
	ft_set_status(1);
}

static void	get_output(t_cmd *cmd, char *file, int mode)
{
	int		tmp_fd;

	if ((tmp_fd = open(file, O_CREAT | O_WRONLY | mode, 0b0110100100)) == -1)
		ft_puterror(file, INVALID_IDENTIFIER);
	else
	{
		ft_close(cmd->fd_out);
		cmd->fd_out = tmp_fd;
	}
}

static void	get_input(t_cmd *cmd, char *file)
{
	int		tmp_fd;

	if ((tmp_fd = open(file, O_RDONLY)) == -1)
	{
		if (errno == EACCES)
			ft_puterror_redir(file, PERMISSION_DENIED);
		else
			ft_puterror_redir(file, NO_SUCH);
	}
	else
	{
		ft_close(cmd->fd_in);
		cmd->fd_in = tmp_fd;
	}
}

/*
** This function evaluates the type of redirection &&
** points cmd->tokens to the argument
*/

static void	ft_redirect(t_cmd *cmd)
{
	char	*redir;
	t_list	*args;

	redir = (char*)cmd->tokens->content;
	args = NULL;
	cmd->tokens = cmd->tokens->next;
	if (cmd->tokens)
		args = fts_lstnew(fts_strdup(cmd->tokens->content));
	ft_translate(&(args));
	ft_clean(&(args));
	if (args && args->next)
		ft_puterror(cmd->tokens->content, AMBIGUOUS_REDIRECT);
	else if (!ft_strcmp(redir, ">>") && args)
		get_output(cmd, args->content, O_APPEND);
	else if (!ft_strcmp(redir, ">") && args)
		get_output(cmd, args->content, O_TRUNC);
	else if (!ft_strcmp(redir, "<") && args)
		get_input(cmd, args->content);
	else
		ft_puterror_syntax(NULL);
	ft_lstclear(&args, free);
}

/*
** This function finds redirections and suppress them from the tokens.
*/

void		get_redir(t_cmd *cmd)
{
	char	*content;
	t_list	*tmp_tokens;
	t_list	*new_tokens;

	new_tokens = NULL;
	tmp_tokens = cmd->tokens;
	while (cmd->tokens)
	{
		content = cmd->tokens->content;
		if (content && ft_isinset(content[0], "<>"))
			ft_redirect(cmd);
		else
			ft_lstadd_back(&new_tokens, fts_lstnew(fts_strdup(content)));
		if (cmd->tokens)
			cmd->tokens = cmd->tokens->next;
	}
	ft_lstclear(&tmp_tokens, free);
	cmd->tokens = new_tokens;
}
