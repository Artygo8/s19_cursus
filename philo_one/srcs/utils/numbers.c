/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:31:27 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/27 14:31:27 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_atoi(const char *str)
{
	int		i;
	size_t	value;

	i = 0;
	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
		value = ((value * 10) + (str[i++] - '0'));
	return (value);
}

int		ft_gt_max_ulong(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > ft_strlen(MAX_ULONG))
		return (TRUE);
	else if (i < ft_strlen(MAX_ULONG))
		return (FALSE);
	else if (i == ft_strlen(MAX_ULONG))
	{
		i = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] > MAX_ULONG[i])
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

int		ft_is_ulong(const char *str)
{
	int i;

	i = 0;
	if (*str == '-')
		return (FALSE);
	while (str[i] == '0')
		i++;
	if (ft_gt_max_ulong(&str[i]))
		return (FALSE);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (TRUE);
	return (FALSE);
}

void	ft_putunbr(size_t n)
{
	if (n / 10)
		ft_putunbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}
