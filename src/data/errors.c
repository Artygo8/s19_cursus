/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_puterror(char *content, int error)
{
	fts_putstr_fd("minishell: ", STDERR_FILENO);
	fts_putstr_fd(content, STDERR_FILENO);
	if (error == COMMAND_NOT_FOUND && (error = 127))
		fts_putstr_fd(": command not found", STDERR_FILENO);
	if (error == NO_SUCH && (error = 127))
		fts_putstr_fd(": No such file or directory", STDERR_FILENO);
	if (error == IS_DIR && (error = 126))
		fts_putstr_fd(": is a directory", STDERR_FILENO);
	if (error == PERMISSION_DENIED && (error = 126))
		fts_putstr_fd(": Permission denied", STDERR_FILENO);
	if (error == AMBIGUOUS_REDIRECT)
		fts_putstr_fd(": ambiguous redirect", STDERR_FILENO);
	if (error == MALLOC_ERROR)
		fts_putstr_fd(": malloc error", STDERR_FILENO);
	fts_putchar_fd('\n', STDERR_FILENO);
	ft_set_status(error);
}

void	ft_puterror_syntax(char *content)
{
	fts_putstr_fd("minishell: syntax error near unexpected token `",
																STDERR_FILENO);
	if (!content || content[0] == 0)
		fts_putstr_fd("newline", STDERR_FILENO);
	else
	{
		fts_putchar_fd(content[0], STDERR_FILENO);
		if (content[0] == content[1])
			fts_putchar_fd(content[1], STDERR_FILENO);
	}
	fts_putstr_fd("'\n", STDERR_FILENO);
	ft_set_status(STDERR_FILENO);
}

void	ft_puterror_ueof(char *content)
{
	fts_putstr_fd("minishell: unexpected EOF while looking for matching `",
																STDERR_FILENO);
	fts_putstr_fd(content, STDERR_FILENO);
	fts_putstr_fd("'\n", STDERR_FILENO);
	ft_set_status(UNEXPECTED_EOF);
}
