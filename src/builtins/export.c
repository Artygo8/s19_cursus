/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_puterror_export(char *content, int error)
{
	fts_putstr_fd("minishell: export: `", STDERR_FILENO);
	fts_putstr_fd(content, STDERR_FILENO);
	if (error == INVALID_IDENTIFIER)
		fts_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	ft_set_status(error);
}

static int	ft_is_valid_identifier(char *identifier)
{
	if (!identifier || ft_isinset(*identifier, "0123456789="))
		return (FALSE);
	while (*identifier && *identifier != '=')
	{
		if (ft_isinset(*identifier, "!@'$|\"&/;? \t\\"))
			return (FALSE);
		identifier++;
	}
	return (TRUE);
}

static void	ft_export_noargs(int fd)
{
	char	*variable;
	size_t	i;
	t_list	*cpy_env;

	cpy_env = *ft_get_env();
	while (cpy_env)
	{
		i = 0;
		variable = fts_strdup(cpy_env->content);
		fts_putstr_fd("declare -x ", fd);
		while (variable[i] != '=')
			fts_putchar_fd(variable[i++], fd);
		fts_putchar_fd(variable[i++], fd);
		fts_putchar_fd('"', fd);
		while (variable[i])
		{
			if (variable[i] == '"')
				fts_putchar_fd('\\', fd);
			fts_putchar_fd(variable[i++], fd);
		}
		fts_putstr_fd("\"\n", fd);
		free(variable);
		cpy_env = cpy_env->next;
	}
}

void		ft_export(t_list *args, int fd)
{
	if (!args)
		ft_export_noargs(fd);
	while (args)
	{
		if (!ft_is_valid_identifier(args->content))
			ft_puterror_export(args->content, INVALID_IDENTIFIER);
		else
			ft_assign_to_env(args->content);
		args = args->next;
	}
}
