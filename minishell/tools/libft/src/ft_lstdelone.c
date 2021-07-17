/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:27:34 by agossuin          #+#    #+#             */
/*   Updated: 2020/02/25 15:41:04 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst && lst->content)
	{
		(*del)(lst->content);
		lst->content = NULL;
	}
	if (lst && lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}
