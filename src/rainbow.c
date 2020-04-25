/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:16 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/25 18:41:05 by agossuin         ###   ########.fr       */
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

size_t		ft_mult_color(size_t color, float m)
{
	size_t res;
	size_t add;

	res = (int)((color & B) * m) & B;
	if (res > B)
		res = B;
	add = (color & G) * m;
	if (add > (G | B))
		add = G;
	res += add & G;
	add = (color & R) * m;
	if (res > (R | G | B))
		add = R;
	res += add & R;
	return (res);
}

size_t		ft_rainbow(float ratio)
{
	int col;

	ratio = ratio * 6;
	if (ratio < 1)
		col = R + ft_mult_color(G, sin_aprox(ratio * PI / 2));
	else if (ratio < 2)
		col = G + ft_mult_color(R, cos_aprox((ratio - 1) * PI / 2));
	else if (ratio < 3)
		col = G + ft_mult_color(B, sin_aprox((ratio - 2) * PI / 2));
	else if (ratio < 4)
		col = B + ft_mult_color(G, cos_aprox((ratio - 3) * PI / 2));
	else if (ratio < 5)
		col = B + ft_mult_color(R, sin_aprox((ratio - 4) * PI / 2));
	else
		col = R + ft_mult_color(B, cos_aprox((ratio - 5) * PI / 2));
	return (col);
}
