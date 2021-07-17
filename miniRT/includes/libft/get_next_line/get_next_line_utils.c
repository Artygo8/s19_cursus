/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:02:37 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/18 14:02:41 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_pos(const char *s, int c)
{
	int pos;

	pos = 0;
	while (s && s[pos])
	{
		if (s[pos] == c)
			return (pos);
		pos++;
	}
	if (s && s[pos] == c)
		return (pos);
	return (-1);
}

char	*ft_strjoin_to_eol(char *s1, char *buf)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		i++;
	while (buf && buf[j] && buf[j] != '\n')
		j++;
	if (!(tab = malloc(i + j + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	while (buf && *buf && *buf != '\n')
		tab[i++] = *buf++;
	tab[i] = 0;
	free(s1);
	return (tab);
}
