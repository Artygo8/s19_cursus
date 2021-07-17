/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:30:02 by agossuin          #+#    #+#             */
/*   Updated: 2020/09/08 17:33:57 by pmaldag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_double_quote_dup(char **line_ptr)
{
	char	*dup;

	dup = fts_strdup("");
	dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	while (**line_ptr && **line_ptr != '"')
	{
		if (**line_ptr == '\\')
			dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	}
	if (**line_ptr == '"')
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	else
		ft_puterror_ueof("\"");
	return (dup);
}

char	*ft_single_quote_dup(char **line_ptr)
{
	char	*dup;

	dup = fts_strdup("");
	dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	while (**line_ptr && **line_ptr != '\'')
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	if (**line_ptr == '\'')
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	else
		ft_puterror_ueof("\'");
	return (dup);
}

char	*ft_operator_dup(char **line_ptr)
{
	char	*dup;

	if (ft_isinset(**line_ptr, "|;"))
		return (fts_chardup(*(*line_ptr)++));
	dup = fts_strdup("");
	if (ft_isinset(**line_ptr, "<>"))
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	if (ft_isinset(**line_ptr, "<>"))
		dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
	return (dup);
}

char	*ft_simple_dup(char **line_ptr)
{
	char	*dup;

	dup = fts_strdup("");
	while (**line_ptr && !ft_isinset(**line_ptr, " \t|;<>"))
	{
		if (**line_ptr == '"')
			dup = fts_strjoinfree(dup, ft_double_quote_dup(line_ptr));
		else if (**line_ptr == '\'')
			dup = fts_strjoinfree(dup, ft_single_quote_dup(line_ptr));
		else
		{
			if (**line_ptr == '\\')
				dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
			if (**line_ptr)
				dup = fts_strjoinfree(dup, fts_chardup(*(*line_ptr)++));
		}
	}
	return (dup);
}

/*
** Keeps everything as it is, only separates into tokens.
*/

t_list	*ft_lexer(char *line)
{
	t_list	*lexer;
	int		previous;

	lexer = NULL;
	previous = FALSE;
	while (line && *line)
	{
		if (ft_isinset(*line, " \t"))
			line++;
		else if ((ft_isinset(*line, ";|") && (lexer == NULL || previous)
			&& !(line[1] = 0)) || (ft_isinset(*line, "><") && previous))
		{
			ft_puterror_syntax(line);
			return (lexer);
		}
		else if (ft_isinset(*line, OPERATORS) && (previous = *line))
			ft_lstadd_back(&lexer, fts_lstnew(ft_operator_dup(&line)));
		else if (!(previous = FALSE))
			ft_lstadd_back(&lexer, fts_lstnew(ft_simple_dup(&line)));
	}
	if (ft_isinset(previous, "|><"))
		ft_puterror_syntax(NULL);
	return (lexer);
}
