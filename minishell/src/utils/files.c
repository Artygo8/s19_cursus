/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int			ft_file_readable(char *path)
{
	struct stat stats;

	if (stat(path, &stats) == 0)
	{
		if (stats.st_mode & S_IRUSR)
			return (TRUE);
	}
	return (FALSE);
}

int			ft_file_permitted(char *path)
{
	struct stat stats;

	if (stat(path, &stats) == 0)
	{
		if (stats.st_mode & S_IXUSR)
			return (TRUE);
	}
	return (FALSE);
}

int			ft_file_directory(char *path)
{
	struct stat stats;

	if (stat(path, &stats) == 0)
	{
		if (stats.st_mode & DIRECTORY_STATS)
			return (TRUE);
	}
	return (FALSE);
}

int			ft_file_exists(char *path)
{
	struct stat stats;

	if (stat(path, &stats) == 0)
		return (TRUE);
	return (FALSE);
}

void		ft_close(int fd)
{
	if (fd > 2)
		close(fd);
}
