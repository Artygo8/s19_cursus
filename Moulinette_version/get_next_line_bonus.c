/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:01:46 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/18 14:01:50 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				ret;
	int				i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX || !line
					|| !(*line = ft_strjoin_to_eol(NULL, buf[fd])))
		return (-1);
	ret = 1;
	while (ft_strchr_pos(buf[fd], '\n') == -1 && ret && ret != -1)
	{
		ft_bzero(buf[fd], BUFFER_SIZE + 1);
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (!(*line = ft_strjoin_to_eol(*line, buf[fd])))
			return (-1);
	}
	i = 0;
	ret = ft_strchr_pos(buf[fd], '\n') + 1;
	if (buf[fd][0] == 0)
		return (0);
	while (buf[fd][ret] != '\0' && ret)
		buf[fd][i++] = buf[fd][ret++];
	buf[fd][i] = 0;
	return (1);
}
