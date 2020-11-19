/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		*ft_is_child_process(void)
{
	static int is_child = FALSE;

	return (&is_child);
}

void	ft_set_child_process(int bool)
{
	int	*is_child_ptr;

	is_child_ptr = ft_is_child_process();
	*is_child_ptr = bool;
}
