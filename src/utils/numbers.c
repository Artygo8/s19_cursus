/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		ft_gt_max_llong(char *str, int is_neg)
{
	size_t i;

	i = 0;
	while (ft_isinset(str[i], "0123456789"))
		i++;
	if (i > ft_strlen(MAX_LLONG))
		return (TRUE);
	else if (i < ft_strlen(MAX_LLONG))
		return (FALSE);
	else if (i == ft_strlen(MAX_LLONG))
	{
		i = 0;
		while (ft_isinset(str[i], "0123456789"))
		{
			if ((is_neg && str[i] > MAX_LLONG_NEG[i])
			|| (!is_neg && str[i] > MAX_LLONG[i]))
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

int		ft_is_numeric(char *str)
{
	int i;
	int is_neg;

	i = 0;
	is_neg = FALSE;
	while (ft_isinset(*str, "\t\f\r "))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = TRUE;
		str++;
	}
	while (str[i] == '0')
		i++;
	if (ft_gt_max_llong(&str[i], is_neg))
		return (FALSE);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (ft_isinset(str[i], "\t "))
		i++;
	if (str[i] == '\0')
		return (TRUE);
	return (FALSE);
}
