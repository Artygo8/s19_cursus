/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_pwddup(void)
{
	char	tmp[1024];
	size_t	len;

	getcwd(tmp, 1024);
	len = ft_strlen("/System/Volumes/Data");
	if (!ft_strncmp("/System/Volumes/Data", tmp, len))
		return (fts_strjoin("/", &tmp[len]));
	return (fts_strdup(tmp));
}

void	ft_set_oldpwd(void)
{
	char *oldpwd;

	oldpwd = fts_strjoinfree(fts_strdup("OLDPWD="), ft_vardup_from_env("PWD"));
	ft_assign_to_env(oldpwd);
	free(oldpwd);
}

void	ft_set_pwd(void)
{
	char *pwd;
	char *pwd_var;

	pwd = ft_pwddup();
	pwd_var = fts_strjoin("PWD=", pwd);
	ft_assign_to_env(pwd_var);
	free(pwd);
	free(pwd_var);
}

void	ft_pwd(int fd)
{
	char *pwd;

	pwd = ft_pwddup();
	fts_putstr_fd(pwd, fd);
	free(pwd);
	fts_putstr_fd("\n", fd);
}
