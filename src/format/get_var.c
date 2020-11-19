/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int			ft_same_var(char *assignation, char *var)
{
	size_t i;

	i = 0;
	while (var[i] && var[i] != '=' && assignation[i])
	{
		if (var[i] != assignation[i])
			return (FALSE);
		i++;
	}
	if (assignation[i] != '=')
		return (FALSE);
	return (TRUE);
}

char		*ft_vardup_from_env(char *str)
{
	t_list	*cpy_env;
	size_t	size;

	cpy_env = *ft_get_env();
	size = ft_strlen(str);
	while (cpy_env && size)
	{
		if (cpy_env->content && ft_same_var(cpy_env->content, str))
			return (fts_strdup(&(((char*)cpy_env->content)[size + 1])));
		cpy_env = cpy_env->next;
	}
	return (NULL);
}

void		ft_assign_to_env(char *var)
{
	t_list	**env_ptr;
	t_list	*cpy_env;
	size_t	size;

	env_ptr = ft_get_env();
	cpy_env = *env_ptr;
	size = 0;
	while (var[size] && var[size] != '=')
		size++;
	if (var[size] != '=')
		return ;
	while (cpy_env)
	{
		if (cpy_env->content && ft_same_var(cpy_env->content, var))
		{
			free(cpy_env->content);
			cpy_env->content = fts_strdup(var);
			return ;
		}
		cpy_env = cpy_env->next;
	}
	ft_lstadd_back(env_ptr, fts_lstnew((void*)fts_strdup(var)));
}

char		*get_value(char **line_ptr)
{
	char	*var;
	char	*value;
	int		bracket;

	bracket = FALSE;
	var = NULL;
	(*line_ptr)++;
	if (*(*line_ptr) == '?' && (*line_ptr)++)
		return (ft_itoa(*ft_get_last_status()));
	if (*(*line_ptr) == '{' && (bracket = TRUE))
		(*line_ptr)++;
	while (ft_isalnum(*(*line_ptr)) || *(*line_ptr) == '_')
		var = fts_strjoinfree(var, fts_chardup(*(*line_ptr)++));
	if (bracket == TRUE)
		(*line_ptr)++;
	value = ft_vardup_from_env(var);
	free(var);
	return (value);
}

int			ft_is_valid_var(char *str)
{
	int i;

	i = 0;
	if (!(str[i++] == '$'))
		return (FALSE);
	if (str[i] == '?')
		return (TRUE);
	if (str[i] == '{')
	{
		i++;
		while (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		if (str[i] != '}' || i == 2)
		{
			ft_puterror("invalid variable format", INVALID_IDENTIFIER);
			return (FALSE);
		}
		return (TRUE);
	}
	else
		return ((ft_isalnum(str[i]) || str[i] == '_'));
}
