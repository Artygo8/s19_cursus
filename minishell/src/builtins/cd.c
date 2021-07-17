/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_puterror_cd(char *content, int error)
{
	fts_putstr_fd("minishell: cd: ", STDERR_FILENO);
	if (content)
		fts_putstr_fd(content, STDERR_FILENO);
	if (error == PERMISSION_DENIED)
		fts_putstr_fd(": Permission denied\n", STDERR_FILENO);
	if (error == NO_SUCH)
		fts_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	if (error == HOME_NOT_SET)
		fts_putstr_fd("HOME not set\n", STDERR_FILENO);
	ft_set_status(error);
}

static int	ft_cd_home(void)
{
	char	*home;

	home = ft_vardup_from_env("HOME");
	if (!home)
		return (FALSE);
	chdir(home);
	free(home);
	return (TRUE);
}

void		ft_cd(t_list *tokens)
{
	if (!tokens)
	{
		if (!ft_cd_home())
			ft_puterror_cd(NULL, HOME_NOT_SET);
		else
		{
			ft_set_oldpwd();
			ft_set_pwd();
		}
	}
	else if (tokens->content && !ft_file_exists(tokens->content))
		ft_puterror_cd(tokens->content, NO_SUCH);
	else if (tokens->content && !ft_file_permitted(tokens->content))
		ft_puterror_cd(tokens->content, PERMISSION_DENIED);
	else
	{
		if (tokens->content && chdir(tokens->content) != 0)
			ft_puterror_cd(tokens->content, NO_SUCH);
		ft_set_oldpwd();
		ft_set_pwd();
	}
}
