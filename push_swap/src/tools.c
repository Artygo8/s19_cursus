/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	**get_line(void)
{
	static char *line = NULL;

	return (&line);
}

void	gtfo(const char *status)
{
	ft_putendl_fd((char*)status, STDERR_FILENO);
	free(*get_line());
	my_stacks_delete();
	exit(0);
}

int		is_int(const char *arg)
{
	size_t i;
	size_t len;

	i = 0;
	if (arg[0] == '-')
		++i;
	len = ft_strlen(&arg[i]);
	if (len > 10)
		return (0);
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return (0);
		++i;
	}
	if (len == 10)
	{
		if (ft_atoi(arg) > 0 && arg[0] == '-')
			return (0);
		if (ft_atoi(arg) < 0 && arg[0] != '-')
			return (0);
	}
	return (1);
}
