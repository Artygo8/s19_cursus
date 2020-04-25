/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:04 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/25 18:43:49 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		valid_c(const char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != 0 || i > 3)
		return (0);
	else if (atoi(str) > 255)
		return (0);
	return (1);
}

int		get_flags(const char *str)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	if (str[i++] == 'r')
		flag |= 1;
	else
		return (-1);
	if (str[i])
		flag *= atoi(&str[i++]);
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] != 0 || flag > 255)
		return (-1);
	return (flag);
}

void	color_print(int flag, char *line, char const *argv[])
{
	size_t	l;
	float	ratio;
	int		i;
	int		color;

	if (flag == -1)
		printf("\e[38;2;%s;%s;%sm%s\e[m\n", argv[0], argv[1], argv[2], line);
	else
	{
		i = 0;
		l = strlen(line);
		while (line[i])
		{
			ratio = (float)i / l * flag;
			while (ratio > 1)
				ratio -= 1;
			color = ft_rainbow(ratio) & 0xffffff;
			printf("\e[38;2;%d;%d;%dm%c\e[m", (color & 0xff0000) >> 16,
					(color & 0x00ff00) >> 8, color & 0x0000ff, line[i++]);
		}
		printf("\n");
	}
}

int		main(int argc, char const *argv[])
{
	char	*line;
	int		flag;

	flag = -1;
	if (argc > 1 && argv[1][0] == '-')
		flag = get_flags(argv[1]);
	if ((flag != -1 && argc == 2) || (flag == -1 && argc == 4
		&& valid_c(argv[1]) && valid_c(argv[2]) && valid_c(argv[3])))
	{
		while (get_next_line(&line))
		{
			color_print(flag, line, &argv[1]);
			free(line);
			line = NULL;
		}
	}
	else
		printf("\e[31;2mInvalid argument, try this :\n\
		\"./color [-r][0-255] RRR GGG BBB\"\n\e[m");
	return (0);
}
