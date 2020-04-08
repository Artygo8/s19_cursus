/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:39:09 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/25 13:45:14 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstenv(char **envp)
{
	int		i;
	t_list	*env;

	i = 0;
	env = ft_lstnew((void *)ft_strdup(envp[i++]));
	while (envp[i])
		ft_lstadd_back(&env, ft_lstnew((void *)ft_strdup(envp[i++])));
	return (env);
}

void	ft_putenv(t_list *env)
{
	while (env)
	{
		ft_putendl_fd(env->content, 1);
		env = env->next;
	}
}

int 	ft_var_to_lst(t_list *env, const char *var)
{
	t_list	*cpy_env;
	int		size;

	cpy_env = env;
	size = 0;
	while (var[size] && var[size] != '=')
		size++;
	size++;
	while (env)
	{
		if (env->content && !ft_strncmp(env->content, var, size - 1))
		{
			free(env->content);
			env->content = ft_strdup(var);
			return (0);
		}
		env = env->next;
	}
	ft_lstadd_back(&cpy_env, ft_lstnew((void*)ft_strdup(var)));
	return (0);
}
