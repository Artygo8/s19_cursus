/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_is_echo_arg(char *str)
{
	size_t i;

	i = 0;
	if (!(str[i++] == '-'))
		return (FALSE);
	if (!(str[i++] == 'n'))
		return (FALSE);
	while (str[i] == 'n')
		i++;
	if (str[i])
		return (FALSE);
	return (TRUE);
}

void		ft_echo(t_list *arg, int fd)
{
	int option_n;
	int first;

	first = TRUE;
	option_n = FALSE;
	while (arg && arg->content && ft_is_echo_arg(arg->content))
	{
		option_n = TRUE;
		arg = arg->next;
	}
	while (arg)
	{
		if (!first)
			fts_putstr_fd(" ", fd);
		fts_putstr_fd(arg->content, fd);
		first = FALSE;
		arg = arg->next;
	}
	if (!option_n)
		fts_putstr_fd("\n", fd);
}
