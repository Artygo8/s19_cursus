/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_escape_set(char *value, char *set)
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	while (value && value[i])
	{
		if (ft_isinset(value[i], set))
			new = fts_strjoinfree(new, fts_chardup('\\'));
		new = fts_strjoinfree(new, fts_chardup(value[i++]));
	}
	free(value);
	return (new);
}

static char	*ft_translate_squote(char **token_ptr)
{
	char	*dup;

	dup = NULL;
	dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	while (**token_ptr != '\'')
		dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	return (dup);
}

static char	*ft_translate_dquote(char **token_ptr)
{
	char	*dup;
	int		escape;

	dup = NULL;
	escape = FALSE;
	dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	while (**token_ptr != '"' || escape == TRUE)
	{
		if (escape == TRUE && !(escape = FALSE))
			dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
		else if (**token_ptr == '\\' && (escape = TRUE))
			dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
		else if (ft_is_valid_var(*token_ptr))
			dup = fts_strjoinfree(dup,
				ft_escape_set(get_value(&(*token_ptr)), "\\"));
		else
			dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	}
	dup = fts_strjoinfree(dup, fts_chardup(*(*token_ptr)++));
	return (dup);
}

static char	*ft_translate_token(char *token)
{
	char	*dup;
	int		escape;

	dup = NULL;
	escape = FALSE;
	if (*token == '~' && token++)
		dup = fts_strjoinfree(dup, ft_vardup_from_env("HOME"));
	while (*token)
	{
		if (escape == TRUE && !(escape = FALSE))
			dup = fts_strjoinfree(dup, fts_chardup(*token++));
		else if (*token == '\'')
			dup = fts_strjoinfree(dup, ft_translate_squote(&token));
		else if (*token == '"')
			dup = fts_strjoinfree(dup, ft_translate_dquote(&token));
		else if (*token == '\\' && (escape = TRUE))
			dup = fts_strjoinfree(dup, fts_chardup(*token++));
		else if (ft_is_valid_var(token))
			dup = fts_strjoinfree(dup,
						ft_escape_set(get_value(&token), "\\'"));
		else
			dup = fts_strjoinfree(dup, fts_chardup(*token++));
	}
	return (dup);
}

void		ft_translate(t_list **token_ptr)
{
	t_list	*new;
	t_list	*lexed_list;
	t_list	*tmp_list;
	char	*tmpstr;

	new = NULL;
	tmp_list = *token_ptr;
	while (*token_ptr)
	{
		tmpstr = ft_translate_token((*token_ptr)->content);
		lexed_list = ft_lexer(tmpstr);
		if (lexed_list)
			ft_lstadd_back(&(new), lexed_list);
		free(tmpstr);
		(*token_ptr) = (*token_ptr)->next;
	}
	ft_lstclear(&tmp_list, free);
	*token_ptr = new;
}
