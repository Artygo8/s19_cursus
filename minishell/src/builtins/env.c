/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list		**ft_get_env(void)
{
	static t_list	*env;

	return (&env);
}

// static char	*ft_underscore(void)
// {
// 	char	*underscore;
// 	char	*path;

// 	path = ft_vardup_from_env("PATH");
// 	underscore = fts_strjoin("_=", path);
// 	underscore = fts_strjoinfree(underscore, fts_strdup("/env"));
// 	free(path);
// 	return (underscore);
// }

static void	ft_set_shlvl(void)
{
	char	*shlvl;
	int		lvl;

	lvl = 0;
	shlvl = ft_vardup_from_env("SHLVL");
	if (shlvl)
		lvl = ft_atoi(shlvl);
	if (shlvl && !ft_is_numeric(shlvl))
		lvl = 0;
	free(shlvl);
	if ((lvl == 2147483647 || lvl < 0))
		lvl = -1;
	else if (lvl >= 2000000)
	{
		fts_putstr_fd("minishell: warning: shell level (", STDERR_FILENO);
		fts_putnbr_fd(lvl + 1, STDERR_FILENO);
		fts_putstr_fd(") too high, resetting to 1\n", STDERR_FILENO);
		lvl = 0;
	}
	shlvl = fts_strjoinfree(fts_strdup("SHLVL="), ft_itoa(lvl + 1));
	ft_assign_to_env(shlvl);
	free(shlvl);
}

void		ft_init_env(char **envp)
{
	int		i;
	t_list	**env_ptr;

	i = 0;
	env_ptr = ft_get_env();
	while (envp[i])
		ft_lstadd_back(env_ptr, fts_lstnew((void *)fts_strdup(envp[i++])));
	ft_assign_to_env("_=/bin/bash");
	ft_set_pwd();
	ft_set_shlvl();
}

void		ft_putenv_fd(int fd)
{
	t_list	*cpy_env;
	char	*term;

	ft_assign_to_env("_=/Users/artygo/Desktop/Artygo8-github/minishell_test/bin/env");
	if ((term = ft_vardup_from_env("TERM")))
	{
		ft_putstr_fd("TERM=", fd);
		ft_putendl_fd(term, fd);
	}
	free(term);
	cpy_env = *ft_get_env();
	while (cpy_env)
	{
		if (!ft_same_var(cpy_env->content, "TERM") && !ft_same_var(cpy_env->content, "_"))
		{
			ft_putendl_fd(cpy_env->content, fd);
		}
		cpy_env = cpy_env->next;
	}
	ft_putendl_fd("_=/Users/artygo/Desktop/Artygo8-github/minishell_test/bin/env", fd);
	ft_assign_to_env("_=env");
	// underscore = ft_underscore();
	// ft_putendl_fd(underscore, fd);
	// free(underscore);
}
