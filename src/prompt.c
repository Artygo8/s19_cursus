/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit_from_prompt(int status)
{
	if (status == GNL_ERROR)
		ft_puterror("get_next_line failed", GNL_ERROR);
	if (status == MUST_EXIT)
		fts_putstr_fd("exit\n", 0);
	ft_delete_msh();
	free(*ft_get_msh());
	ft_lstclear(ft_get_env(), free);
	free(*ft_get_env());
	exit(*ft_get_status());
}

int		get_next_char(int fd, char *cptr)
{
	static char	buf;
	int			ret;

	buf = 0;
	if (fd < 0 || fd > FOPEN_MAX || !cptr)
		return (-1);
	ret = read(fd, &buf, 1);
	if (ret == -1)
		ft_puterror("read failed", READING_ERROR);
	else
		*cptr = buf;
	return (ret);
}

int		ft_wait_line(void)
{
	char	c;
	int		ret;

	c = 0;
	while ((ret = get_next_char(STDIN_FILENO, &c)) == 1)
	{
		if (c == '\n')
			break ;
		(*ft_get_msh())->line =
				fts_strjoinfree((*ft_get_msh())->line, fts_chardup(c));
	}
	if (ret == -1)
		ft_exit_from_prompt(GNL_ERROR);
	if (ret == 0)
	{
		if (!(*ft_get_msh())->line || !((*ft_get_msh())->line)[0])
			ft_exit_from_prompt(MUST_EXIT);
	}
	else
	{
		ft_system();
		free((*ft_get_msh())->line);
		(*ft_get_msh())->line = NULL;
	}
	return (1);
}

void	ft_prompt(void)
{
	fts_putstr_fd(PROMPT, STDERR_FILENO);
	while (1)
	{
		ft_set_child_process(FALSE);
		ft_wait_line();
		if (((!(*ft_get_msh())->line || !(*ft_get_msh())->line[0]))
	&& (*ft_get_signal() != SIGINT || *ft_get_last_status() != SIGNAL_CTRL_C))
			fts_putstr_fd(PROMPT, STDERR_FILENO);
		if (*ft_get_signal() == SIGQUIT)
		{
			ft_set_status(SIGNAL_CTRL_BS);
			ft_set_last_status();
		}
		ft_set_signal(0);
	}
}
