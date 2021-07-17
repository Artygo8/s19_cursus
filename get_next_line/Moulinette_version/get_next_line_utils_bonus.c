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

#include "get_next_line_bonus.h"

void	ft_bzero(void *b, size_t len)
{
	while (len > 0)
	{
		*(char *)b++ = 0;
		len--;
	}
}

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
