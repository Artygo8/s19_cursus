/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:21:17 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/08 19:21:18 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** Multiplies the rgb values by a constant.
*/

int		ft_mult_color(int color, float m)
{
	int res;
	int add;

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

/*
** Adds colors to one another.
*/

int		ft_add_color(int color_1, int color_2)
{
	int res;
	int add;

	res = (color_1 & B) + (color_2 & B);
	if (res > B)
		res = B;
	add = (color_1 & G) + (color_2 & G);
	if (add > G)
		add = G;
	res += add;
	add = (color_1 & R) + (color_2 & R);
	if (add > R)
		add = R;
	res += add;
	return (res);
}

/*
** Applies a colored light.
*/

int		ft_enlight(int color, int light, double ratio)
{
	int res;

	res = (int)((color & B) * (double)(light & B) / B * ratio) & B;
	if (res > B)
		res = B;
	res += (int)((color & G) * (double)(light & G) / G * ratio) & G;
	if (res > (G | B))
		res &= (G | B);
	res += (int)((color & R) * (double)(light & R) / R * ratio) & R;
	if (res > (R | G | B))
		res &= (R | G | B);
	return (res);
}

/*
** Applies a color depending on a ratio.
*/

int		ft_rainbow(float ratio)
{
	int col;
	int start;

	start = ratio * 3;
	if (ratio < (1 - ratio))
		ratio /= ratio;
	else
		ratio /= (1 - ratio);
	if (start < 1)
		col = ft_mult_color(R, 1 - ratio) + ft_mult_color(G, ratio);
	else if (start < 2)
		col = ft_mult_color(G, 1 - (ratio - 1)) + ft_mult_color(B, ratio - 1);
	else
		col = ft_mult_color(B, 1 - (ratio - 2)) + ft_mult_color(R, ratio - 2);
	return (col);
}
