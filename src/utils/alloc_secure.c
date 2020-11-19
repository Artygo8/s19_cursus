/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_secure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** These are libft functions modified to generate errors following
** the minishell principles.
** "fts_" stands for "ft_" "secure".
*/

char	*fts_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
	{
		ft_puterror("fts_strjoin", MALLOC_ERROR);
		return (NULL);
	}
	while (s1 && *s1)
		new[i++] = *s1++;
	while (s2 && *s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char	*fts_strdup(const char *s1)
{
	char	*new_s;
	int		i;

	i = 0;
	if (!s1)
		return (fts_strdup(""));
	if (!(new_s = malloc((ft_strlen(s1) + 1) * sizeof(char))))
	{
		ft_puterror("fts_strdup", MALLOC_ERROR);
		return (NULL);
	}
	while (s1 && *s1)
		new_s[i++] = *s1++;
	new_s[i] = '\0';
	return (new_s);
}

void	*fts_calloc(size_t count, size_t size)
{
	void	*s;

	count *= size;
	if (!(s = (void*)malloc(count)))
	{
		ft_puterror("fts_calloc", MALLOC_ERROR);
		return (NULL);
	}
	ft_bzero(s, count);
	return (s);
}

char	*fts_itoa(int nb)
{
	char *str;

	if (!(str = ft_itoa(nb)))
	{
		ft_puterror("fts_itoa", MALLOC_ERROR);
		return (NULL);
	}
	return (str);
}

t_list	*fts_lstnew(void *content)
{
	t_list	*head;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
	{
		ft_puterror("fts_lstnew", MALLOC_ERROR);
		return (NULL);
	}
	head->content = content;
	head->next = NULL;
	return (head);
}
