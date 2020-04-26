/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:16 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 19:02:52 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

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
	return (res);
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

/*
** Rotate takes an index 0, 1, 2 for R, G, B where R is the initial form.
*/

int			rot_color(int start, int index)
{
	int new;

	new = 0;
	if (index == 0)
		return start;
	if (index == 1)
	{
		new = (start & R) >> 16;
		new += (start & G) << 8;
		new += (start & B) << 8;
	}
	if (index == 2)
	{
		new = (start & R) >> 8;
		new += (start & G) >> 8;
		new += (start & B) << 16;
	}
	return (new);
}

size_t		ft_rainbow(float ratio, int s)
{
	int col;

	while (ratio > 1)
		ratio -= 1;
	ratio = ratio * 6;
	if (ratio < 1)
		col = ft_add_color(s, ft_mult_color(rot_color(s, 1),
				sin_aprox(ratio * PI / 2)));
	else if (ratio < 2)
		col = ft_add_color(rot_color(s, 1), ft_mult_color(s,
				cos_aprox((ratio - 1) * PI / 2)));
	else if (ratio < 3)
		col = ft_add_color(rot_color(s, 1), ft_mult_color(rot_color(s, 2),
				sin_aprox((ratio - 2) * PI / 2)));
	else if (ratio < 4)
		col = ft_add_color(rot_color(s, 2), ft_mult_color(rot_color(s, 1),
				cos_aprox((ratio - 3) * PI / 2)));
	else if (ratio < 5)
		col = ft_add_color(rot_color(s, 2), ft_mult_color(s,
				sin_aprox((ratio - 4) * PI / 2)));
	else
		col = ft_add_color(s, ft_mult_color(rot_color(s, 2),
				cos_aprox((ratio - 5) * PI / 2)));
	return (col);
}
