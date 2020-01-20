/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:44:15 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/07 13:44:18 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_ischar(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (ft_atoi(s) > 255)
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (i > 3)
		return (0);
	if (!(ft_isspace(s[i]) || (s[i] == 0) || (s[i] == ',')))
		return (0);
	return (1);
}

int		ft_isrgb(char *s)
{
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (!ft_ischar(s))
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s++ != ',')
		return (0);
	if (!ft_ischar(s))
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s++ != ',')
		return (0);
	if (!ft_ischar(s))
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (!(ft_isspace(*s) || (*s == 0)))
		return (0);
	return (1);
}

int		ft_len_float(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
		i++;
	}
	return (i);
}

int		ft_isfloat(char *s)
{
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		s++;
	if (ft_len_float(s) > (SIZE_MAX_FLOAT - 2))
		return (0);
	if (!ft_isdigit(*s))
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		s++;
		while (ft_isdigit(*s))
			s++;
	}
	if (!(ft_isspace(*s) || (*s == 0) || (*s == ',')))
		return (0);
	return (1);
}

int		ft_isvect(char *s)
{
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (!ft_isfloat(s))
		return (0);
	s += ft_len_float(s);
	if (*s++ != ',')
		return (0);
	if (!ft_isfloat(s))
		return (0);
	s += ft_len_float(s);
	if (*s++ != ',')
		return (0);
	if (!ft_isfloat(s))
		return (0);
	s += ft_len_float(s);
	if (!(ft_isspace(*s) || (*s == 0)))
		return (0);
	return (1);
}
