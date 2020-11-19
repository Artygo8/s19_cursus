/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char		*ft_clean_token(char *token)
{
	char	*dup;
	char	last_quote;

	dup = NULL;
	last_quote = 0;
	while (*token)
	{
		if (last_quote == 0 && (*token == '\'' || *token == '"'))
			last_quote = *token;
		else if (last_quote == 0 && (*token != '\\' || token++))
			dup = fts_strjoinfree(dup, fts_chardup(*token));
		else if (last_quote == '\'' && *token == '\'')
			last_quote = 0;
		else if (last_quote == '\'')
			dup = fts_strjoinfree(dup, fts_chardup(*token));
		else if (*token == '"')
			last_quote = 0;
		else if (*token == '\\' && ft_isinset(*(token + 1), "$\"\\"))
			dup = fts_strjoinfree(dup, fts_chardup(*(++token)));
		else
			dup = fts_strjoinfree(dup, fts_chardup(*token));
		token++;
	}
	return (dup);
}

/*
** This function removes the things that shouldnt be showed such as ', ", \, ...
*/

void			ft_clean(t_list **token_ptr)
{
	t_list	*new;
	char	*tmpstr;
	t_list	*tmp_token;

	new = NULL;
	tmp_token = *token_ptr;
	while (tmp_token)
	{
		tmpstr = ft_clean_token(tmp_token->content);
		ft_lstadd_back(&(new), fts_lstnew(tmpstr));
		tmp_token = tmp_token->next;
	}
	ft_lstclear(token_ptr, free);
	*token_ptr = new;
}
