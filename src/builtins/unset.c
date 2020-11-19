/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_puterror_unset(char *content, int error)
{
	fts_putstr_fd("minishell: unset: `", STDERR_FILENO);
	fts_putstr_fd(content, STDERR_FILENO);
	if (error == INVALID_IDENTIFIER)
		fts_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	ft_set_status(error);
}

static int	ft_is_valid_identifier(char *identifier)
{
	if (!identifier)
		return (FALSE);
	while (*identifier)
	{
		if (ft_isinset(*identifier, "=/;? \t\\"))
			return (FALSE);
		identifier++;
	}
	return (TRUE);
}

void		ft_unset_var(char *var)
{
	t_list	**env_ptr;
	t_list	*cpy_env;
	t_list	*new_env;
	size_t	size;

	size = 0;
	env_ptr = ft_get_env();
	new_env = NULL;
	cpy_env = *env_ptr;
	while (var[size])
		size++;
	while (cpy_env)
	{
		if (ft_strncmp((char*)cpy_env->content, var, size))
			ft_lstadd_back(&new_env, fts_lstnew(fts_strdup(cpy_env->content)));
		cpy_env = cpy_env->next;
	}
	ft_lstclear(env_ptr, free);
	*env_ptr = new_env;
}

void		ft_unset(t_list *args)
{
	while (args)
	{
		if (!ft_is_valid_identifier(args->content))
			ft_puterror_unset(args->content, INVALID_IDENTIFIER);
		else
			ft_unset_var(args->content);
		args = args->next;
	}
}
