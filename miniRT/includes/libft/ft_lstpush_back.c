/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:51:14 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/22 13:51:16 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpush_back(t_list **alst)
{
	t_list	*last;
	t_list	*tmp;

	if (alst && *alst && (*alst)->next)
	{
		last = *alst;
		*alst = (*alst)->next;
		last->next = NULL;
		tmp = ft_lstlast(*alst);
		tmp->next = last;
	}
}
