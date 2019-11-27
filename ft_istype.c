/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:31 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:10:33 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isinset(int c, char *set)
{
	while (set && *set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		ft_isconvert(int c)
{
	if (ft_isinset(c, "cspdiuxX%f"))
		return (1);
	return (0);
}

int		ft_isflag(int c)
{
	if (ft_isinset(c, "-0"))
		return (1);
	return (0);
}
