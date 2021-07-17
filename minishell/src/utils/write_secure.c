/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_secure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** These are libft functions modified to generate errors following
** the minishell principles.
** "fts_" stands for "ft_" "secure".
*/

void	fts_write(int fd, char *str, size_t len)
{
	if (write(fd, str, len) == -1)
		ft_puterror("cannot write", WRITE_ERROR);
}

void	fts_putstr_fd(char *s, int fd)
{
	if (s)
		fts_write(fd, s, ft_strlen(s));
}

void	fts_putchar_fd(char c, int fd)
{
	fts_write(fd, &c, 1);
}

void	fts_putnbr_fd(int n, int fd)
{
	if (n <= 9 && n >= 0)
		fts_putchar_fd(n + 48, fd);
	else if (n > 9)
	{
		fts_putnbr_fd(n / 10, fd);
		fts_putnbr_fd(n % 10, fd);
	}
	else if (n == -2147483648)
		fts_putstr_fd("-2147483648", fd);
	else
	{
		fts_putchar_fd('-', fd);
		fts_putnbr_fd(n * -1, fd);
	}
}
