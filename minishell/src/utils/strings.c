/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*fts_strjoinfree(char *s1, char *s2)
{
	char *new;

	if (!(new = fts_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	free(s2);
	return (new);
}

char	*fts_chardup(char c)
{
	char *dup;

	if (!(dup = (char*)ft_calloc(2, sizeof(char))))
	{
		ft_puterror("chardup", MALLOC_ERROR);
		return (NULL);
	}
	dup[0] = c;
	return (dup);
}

int		ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1));
}

void	ft_lower_str(char *name)
{
	if (name && *name)
		ft_lower_str(name + 1);
	if (name && *name <= 'Z' && *name >= 'A')
		(*name) = (*name) - 'A' + 'a';
}

int		ft_ispath(char *line)
{
	while (*line && !ft_isspace(*line))
	{
		if (*line++ == '/')
			return (TRUE);
	}
	return (FALSE);
}
