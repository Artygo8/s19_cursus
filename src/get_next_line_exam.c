/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_exam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:34 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/25 18:35:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		ft_strlen_endl(char const *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

int		ft_strchr_pos(const char *s, int c)
{
	int pos;

	pos = 0;
	while (s && s[pos] && (s[pos] != c))
		pos++;
	if (s && s[pos] != c)
		pos = -1;
	return (pos);
}

char	*ft_strjoin_to_eol(char *s1, char *buf)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = malloc(ft_strlen_endl(s1) + ft_strlen_endl(buf) + 1)))
		return (NULL);
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	while (buf && *buf && *buf != '\n')
		tab[i++] = *buf++;
	tab[i] = 0;
	free(s1);
	return (tab);
}

int		get_next_line(char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	ret = 1;
	*line = ft_strjoin_to_eol(NULL, buf);
	while (ft_strchr_pos(buf, '\n') == -1 && ret && ret != -1)
	{
		ret = read(0, buf, BUFFER_SIZE);
		buf[ret] = 0;
		*line = ft_strjoin_to_eol(*line, buf);
	}
	if (buf[0] == 0)
		return (0);
	i = 0;
	ret = ft_strchr_pos(buf, '\n') + 1;
	while (buf[ret] != '\0' && ret)
		buf[i++] = buf[ret++];
	buf[i] = 0;
	return (1);
}
