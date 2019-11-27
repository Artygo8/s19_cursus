/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:11 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:10:12 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_sizeof_int(double n)
{
	int size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static double			ft_exponent(double n, int exp)
{
	double res;

	res = 1;
	if (exp < 0)
	{
		while (exp++ < 0)
			res /= n;
	}
	else
	{
		while (exp-- > 0)
			res *= n;
	}
	return (res);
}

char					*ft_ftoa(double n, int precision)
{
	char	*new;
	int		i;
	int		j;
	int		max;

	precision = (precision == -1) ? 6 : precision;
	n += ft_exponent(10, -precision);
	i = (n < 0);
	max = ft_sizeof_int(n);
	new = malloc((max + 1 + precision + 1) * sizeof(char));
	new[0] = '-';
	n = (n < 0) ? -n : n;
	while (max-- > -precision)
	{
		j = 0;
		while ((j * ft_exponent(10, max))
		<= n - ft_exponent(10, max) && j <= 9)
			j++;
		new[i++] = j + '0';
		n -= j * ft_exponent(10, max);
		if (max == 0 && precision != 0)
			new[i++] = '.';
	}
	new[i] = '\0';
	return (new);
}
