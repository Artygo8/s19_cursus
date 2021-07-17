/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:30:02 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/08 17:32:18 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_system_pipe(t_list **lexer_ptr)
{
	t_list	*tmp_pipe;
	t_cmd	*cmd;
	t_sh	*msh;

	ft_set_status(0);
	msh = *ft_get_msh();
	msh->pipeline = get_next_pipeline(lexer_ptr);
	tmp_pipe = msh->pipeline;
	while (tmp_pipe)
	{
		cmd = (t_cmd*)tmp_pipe->content;
		get_redir(cmd);
		if (*ft_get_status() || !cmd->tokens)
		{
			ft_delete_pipeline(&(msh->pipeline));
			return ;
		}
		ft_translate(&(cmd->tokens));
		ft_clean(&(cmd->tokens));
		tmp_pipe = tmp_pipe->next;
	}
	ft_pipeline_recursion(msh->pipeline, STDIN_FILENO);
	ft_delete_pipeline(&(msh->pipeline));
}

void	ft_system(void)
{
	t_list	*tmp_lexer;
	t_sh	*msh;
	int		stdin_cpy;
	int		stdout_cpy;

	msh = *ft_get_msh();
	ft_set_status(0);
	msh->lexer = ft_lexer(msh->line);
	tmp_lexer = msh->lexer;
	if (*ft_get_status() == 0)
	{
		while (tmp_lexer)
		{
			stdin_cpy = dup(STDIN_FILENO);
			stdout_cpy = dup(STDOUT_FILENO);
			ft_system_pipe(&tmp_lexer);
			ft_set_last_status();
			dup2(stdin_cpy, STDIN_FILENO);
			dup2(stdout_cpy, STDOUT_FILENO);
		}
	}
	ft_delete_msh();
}

int		main(int argc, char const *argv[], char **envp)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTERM, signal_handler);
	ft_init_env(envp);
	ft_init_msh();
	if (argc == 3 && !ft_strcmp((char*)argv[1], "-c"))
	{
		(*ft_get_msh())->line = fts_strdup((char*)argv[2]);
		ft_system();
	}
	else
		ft_prompt();
	ft_delete_msh();
	free(*ft_get_msh());
	ft_lstclear(ft_get_env(), free);
	free(*ft_get_env());
	return (*ft_get_status());
}
