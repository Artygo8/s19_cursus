/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_sh	**ft_get_msh(void)
{
	static t_sh *msh = NULL;

	return (&msh);
}

void	ft_init_msh(void)
{
	t_sh	**msh_ptr;

	msh_ptr = ft_get_msh();
	if (!*msh_ptr)
		*msh_ptr = (t_sh *)fts_calloc(1, sizeof(t_sh));
}

/*
** the cmd itself is not freed, because it is freed from the ft_delete_pipeline
*/

void	ft_delete_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		ft_close(cmd->fd_in);
		ft_close(cmd->fd_out);
		ft_close(cmd->pipe_in);
		ft_close(cmd->pipe_out);
		ft_lstclear(&(cmd->tokens), free);
	}
}

void	ft_delete_pipeline(t_list **pipeline_ptr)
{
	t_list	*cpy_pl;

	cpy_pl = *pipeline_ptr;
	while (cpy_pl)
	{
		if (cpy_pl->content)
			ft_delete_cmd(cpy_pl->content);
		cpy_pl = cpy_pl->next;
	}
	ft_lstclear(pipeline_ptr, free);
	*pipeline_ptr = NULL;
}

void	ft_delete_msh(void)
{
	t_sh	**msh_ptr;

	msh_ptr = ft_get_msh();
	free((*msh_ptr)->line);
	(*msh_ptr)->line = NULL;
	ft_lstclear(&((*msh_ptr)->lexer), free);
	ft_delete_pipeline(&((*msh_ptr)->pipeline));
}
