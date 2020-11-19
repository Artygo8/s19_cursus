/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t		ft_lstlen(t_list *lst)
{
	t_list	*cpy;
	size_t	len;

	len = 0;
	cpy = lst;
	while (cpy)
	{
		len += 1;
		cpy = cpy->next;
	}
	return (len);
}

char		**ft_lsttotable(t_list *lst)
{
	char	**table;
	t_list	*lst_cpy;
	size_t	i;

	i = 0;
	lst_cpy = lst;
	if (!(table = (char**)fts_calloc((ft_lstlen(lst) + 1), sizeof(char*))))
		return (NULL);
	while (lst_cpy)
	{
		if (!(table[i++] = fts_strdup(lst_cpy->content)))
		{
			i = 0;
			while (table[i])
				free(table[i++]);
			return (NULL);
		}
		lst_cpy = lst_cpy->next;
	}
	return (table);
}

void		ft_free_table(char **table)
{
	void *cpy_table;

	cpy_table = table;
	while (table && *table)
		free(*table++);
	free(cpy_table);
}

void		ft_lstput(t_list *lst)
{
	t_list *tmp_lst;

	tmp_lst = lst;
	while (tmp_lst)
	{
		fts_putstr_fd(tmp_lst->content, STDOUT_FILENO);
		fts_putchar_fd('\n', STDOUT_FILENO);
		tmp_lst = tmp_lst->next;
	}
}
