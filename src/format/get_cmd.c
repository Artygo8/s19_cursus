/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_cmd	*get_next_cmd(t_list **tokens_ptr)
{
	t_cmd	*cmd;

	cmd = (t_cmd*)fts_calloc(1, sizeof(t_cmd));
	while (*tokens_ptr)
	{
		if (ft_isinset(((char*)(*tokens_ptr)->content)[0], "|;"))
		{
			if (((char*)(*tokens_ptr)->content)[0] == ';')
				cmd->end = SEMI;
			if (((char*)(*tokens_ptr)->content)[0] == '|')
				cmd->end = PIPE;
			*tokens_ptr = (*tokens_ptr)->next;
			break ;
		}
		ft_lstadd_back(&(cmd->tokens),
				fts_lstnew(fts_strdup((*tokens_ptr)->content)));
		*tokens_ptr = (*tokens_ptr)->next;
	}
	cmd->fd_out = 1;
	return (cmd);
}

t_list			*get_next_pipeline(t_list **tokens_ptr)
{
	t_cmd	*tmp_cmd;
	t_list	*pipeline;

	pipeline = NULL;
	while (*tokens_ptr)
	{
		tmp_cmd = get_next_cmd(tokens_ptr);
		ft_lstadd_back(&pipeline, fts_lstnew(tmp_cmd));
		if (tmp_cmd->end == SEMI)
			break ;
	}
	return (pipeline);
}
