/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:21:05 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/08 19:21:07 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	ft_atof(char *s)
{
	int		i;
	double	deci;
	double	res;

	i = 0;
	deci = 0;
	res = (double)ft_atoi(s);
	while (ft_isspace(*s))
		s++;
	while (ft_isdigit(*s) || *s == '-')
		s++;
	if (*s == '.')
	{
		s++;
		deci = (double)ft_atoi(s);
		while (ft_isdigit(s[i]))
			i++;
		deci *= pow(10, (-1) * i);
	}
	return (res + deci);
}

t_vect	ft_atovect(char *s)
{
	t_vect v;

	v.x = ft_atof(s);
	while (ft_isspace(*s))
		s++;
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	s++;
	v.y = ft_atof(s);
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	s++;
	v.z = ft_atof(s);
	return (v);
}

int		ft_atocol(char *s)
{
	int c;

	c = ft_atoi(s) * 0x10000;
	while (ft_isspace(*s))
		s++;
	while (ft_isdigit(*s) || *s == '-')
		s++;
	s++;
	c += ft_atoi(s) * 0x100;
	while (ft_isdigit(*s) || *s == '-')
		s++;
	s++;
	c += ft_atoi(s);
	return (c);
}
