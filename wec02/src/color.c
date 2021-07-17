/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:04 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 22:00:11 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	print_char(char c, t_cmd *cmd)
{
	if (cmd->revrb != 0)
		printf("\e[%d;%d;38;2;%d;%d;%d;48;2;%d;%d;%dm%c\e[m", cmd->underlined,
		cmd->bold,(cmd->color & R) >> 16, (cmd->color & G) >> 8, cmd->color & B,
		(cmd->color_bg & R) >> 16, (cmd->color_bg & G) >> 8, cmd->color_bg & B, c);
	else
		printf("\e[%d;%d;38;2;%d;%d;%dm%c\e[m", cmd->underlined,
		cmd->bold,(cmd->color & R) >> 16, (cmd->color & G) >> 8, cmd->color & B,
		c);
}

void	ft_print_double_rainbow(char *line, t_cmd *cmd)
{
	size_t	l;
	float	ratio;
	float	ratio_bg;
	int		i;

	i = 0;
	l = strlen(line);
	while (line[i])
	{
		ratio = (float)i / l * cmd->rb;
		ratio_bg = (float)i / l * cmd->revrb + 0.5;
		cmd->color = ft_rainbow(ratio, cmd->start);
		cmd->color_bg = ft_rainbow(ratio_bg, cmd->start);
		print_char(line[i++], cmd);
	}
	printf("\n");
}

void	ft_print_reverse_rainbow(char *line, t_cmd *cmd)
{
	size_t	l;
	float	ratio_bg;
	int		i;

	i = 0;
	l = strlen(line);
	while (line[i])
	{
		ratio_bg = (float)i / l * cmd->revrb;
		cmd->color = 0x222222;
		cmd->color_bg = ft_rainbow(ratio_bg, cmd->start);
		print_char(line[i++], cmd);
	}
	printf("\n");
}

void	ft_print_rainbow(char *line, t_cmd *cmd)
{
	size_t	l;
	float	ratio;
	int		i;

	i = 0;
	l = strlen(line);
	while (line[i])
	{
		ratio = (float)i / l * cmd->rb;
		cmd->color = ft_rainbow(ratio, cmd->start);
		print_char(line[i++], cmd);
	}
	printf("\n");
}

void	ft_print_random_colors(char *line, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (line[i])
	{
		cmd->color = rand() * ((int)cmd->rb + (int)cmd->revrb + cmd->random +
		cmd->start + cmd->revstart + cmd->bold + cmd->underlined +
		cmd->color + cmd->color_bg + strlen(line)) % 0x1000000;
		print_char(line[i++], cmd);
	}
	printf("\n");
}
