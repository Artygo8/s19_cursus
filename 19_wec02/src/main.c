/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 17:25:07 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 20:09:48 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	ft_printer(char *line, t_cmd *cmd)
{
	printf("\e[%d;%d;38;2;%d;%d;%dm%s\e[m\n", cmd->bold, cmd->underlined,
	(cmd->start & R) >> 16, (cmd->start & G) >> 8, cmd->start & B, line);
}

void	ft_colorize(t_cmd *cmd)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (cmd->random != 0)
			ft_print_random_colors(line, cmd);
		else if (cmd->rb != 0 && cmd->revrb != 0)
			ft_print_double_rainbow(line, cmd);
		else if (cmd->rb != 0)
			ft_print_rainbow(line, cmd);
		else if (cmd->revrb != 0)
			ft_print_reverse_rainbow(line, cmd);
		else
			ft_printer(line, cmd);
		free(line);
		line = NULL;
	}
}

int		main(int argc, char const *argv[])
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(cmd))))
	{
		printf("Malloc Failed\n");
		return (-1);
	}
	bzero((void*)cmd, sizeof(cmd));
	cmd->start = 0xffffff;
	if (ft_parsing(argc, argv, cmd) == -1)
		printf("%s\n%s", ERROR, USAGE);
	else
		ft_colorize(cmd);
	return (0);
}
