/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:04:49 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/23 14:05:05 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (lst && f && del)
	{
		while (lst)
		{
			if ((new = ft_lstnew(f(lst->content))))
				ft_lstadd_back(&new, new);
			else
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
