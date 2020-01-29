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
	add = (color & ALPHA) * m;
	res += add & ALPHA;
	return (res);
}

/*
** Adds colors to one another.
*/

size_t		ft_add_color(size_t color_1, size_t color_2)
{
	size_t res;
	size_t add;

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
	add = (color_1 & ALPHA) + (color_2 & ALPHA);
	res += add & ALPHA;
	return (res);
}

/*
** Applies a colored light.
*/

size_t		ft_enlight(size_t color, size_t light, double ratio)
{
	size_t res;

	res = (size_t)((color & B) * (double)(light & B) / B * ratio) & B;
	if (res > B)
		res = B;
	res += (size_t)((color & G) * (double)(light & G) / G * ratio) & G;
	if (res > (G | B))
		res &= (G | B);
	res += (size_t)((color & R) * (double)(light & R) / R * ratio) & R;
	if (res > (R | G | B))
		res &= (R | G | B);
	res += (size_t)((color & ALPHA) * (double)(light & ALPHA)
		/ ALPHA * ratio) & ALPHA;
	return (res);
}

/*
** Applies a color depending on a ratio.
*/

size_t		ft_rainbow(float ratio)
{
	int col;

	ratio = ratio * 6;
	if (ratio < 1)
		col = R + ft_mult_color(G, sin(ratio * PI / 2));
	else if (ratio < 2)
		col = G + ft_mult_color(R, cos((ratio - 1) * PI / 2));
	else if (ratio < 3)
		col = G + ft_mult_color(B, sin((ratio - 2) * PI / 2));
	else if (ratio < 4)
		col = B + ft_mult_color(G, cos((ratio - 3) * PI / 2));
	else if (ratio < 5)
		col = B + ft_mult_color(R, sin((ratio - 4) * PI / 2));
	else
		col = R + ft_mult_color(B, cos((ratio - 5) * PI / 2));
	return (col);
}

int			ft_filter(t_data *data, char *line)
{
	int		valid;

	valid = 1;
	data->filter &= ft_atocol(line);
	valid &= ft_isrgb(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	return (valid);
}
