/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 18:54:50 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 18:55:20 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int			fact(int n)
{
	if (n == 0)
		return (1);
	return (n * fact(n - 1));
}

/*
** after comparing to the math.h sin, max = 6 is the best approximation.
*/

float		sin_aprox(float rad)
{
	int		i;
	float	x;
	int		max;
	float	res;

	i = 0;
	x = rad;
	max = 6;
	res = 0;
	while (i < max)
	{
		res += ((i % 2) ? -1 : 1) * x / fact((2 * i) + 1);
		x *= rad * rad;
		i++;
	}
	if (res > 1)
		return (1);
	if (res < -1)
		return (-1);
	return (res);
}

float		cos_aprox(float rad)
{
	return (-sin_aprox(rad - PI / 2));
}
