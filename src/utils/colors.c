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

	ratio = ratio * 6;
	if (ratio < 1) //rouge a jaune
		col = R + ft_mult_color(G, sin(ratio * PI / 2));
	else if (ratio < 2) //jaune a vert
		col = G + ft_mult_color(R, cos((ratio - 1) * PI / 2));
	else if (ratio < 3) //vert a cyan
		col = G + ft_mult_color(B, sin((ratio - 2) * PI / 2));
	else if (ratio < 4) //cyan a bleu
		col = B + ft_mult_color(G, cos((ratio - 3) * PI / 2));
	else if (ratio < 5) //bleu a violet
		col = B + ft_mult_color(R, sin((ratio - 4) * PI / 2));
	else if (ratio < 6) //violet a rouge
		col = R + ft_mult_color(B, cos((ratio - 5) * PI / 2));
	return (col);
}
