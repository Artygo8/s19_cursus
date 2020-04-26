/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:11:28 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 21:45:27 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		ft_isfloat(const char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (atof(str) > 255)
		return (0);
	if (str[i] == 0)
		return (1);
	return (0);
}

int		ft_iscolor(const char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (atoi(str) > 255)
		return (0);
	if (str[i] == 0)
		return (1);
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i <= n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_parsing(int argc, char const *argv[], t_cmd *cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = strdup(argv[i]);
		if (i + 2 < argc && ft_iscolor(tmp) && ft_iscolor(argv[i + 1]) && ft_iscolor(argv[i + 2]))
		{
			cmd->start = (atoi(tmp) << 16) + (atoi(argv[i + 1]) << 8) + atoi(argv[i + 2]);
			i += 2;
		}
		else if (!ft_strncmp(tmp, "-rr", 4))
		{
			cmd->revrb = 1;
			if (cmd->start == 0xffffff)
				cmd->start = R;
			if (i + 1 < argc && ft_isfloat(argv[i + 1]))
				cmd->revrb = atof(argv[++i]);
		}
		else if (!ft_strncmp(tmp, "-r", 3))
		{
			cmd->rb = 1;
			if (cmd->start == 0xffffff)
				cmd->start = R;
			if (i + 1 < argc && ft_isfloat(argv[i + 1]))
				cmd->rb = atof(argv[++i]);
		}
		else if (!ft_strncmp(tmp, "-bold", 6))
			cmd->bold = 1;
		else if (!ft_strncmp(tmp, "-underlined", 11))
			cmd->underlined = 4;
		else if (!ft_strncmp(tmp, "-random", 8))
			cmd->random = 1;
		else
			return (-1);
		i++;
	}
	return (0);
}
