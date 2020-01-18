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

	res = (color & B) * m;
	if (res > B)
		res = B;
	res += (color & G) * m;
	if (res > (G | B))
		res &= (G | B);
	res += (color & R) * m;
	if (res > (R | G | B))
		res &= (R | G | B);
	return (res);
}

/*
** Adds colors to one another.
*/

int		ft_add_color(int color_1, int color_2)
{
	int res;

	res = (color_1 & 0xff) + (color_2 & 0xff);
	if (res > B)
		res = B;
	res += (color_1 & 0xff00) + (color_2 & 0xff00);
	if (res > (G | B))
		res = G + (res & B);
	res += (color_1 & 0xff0000) + (color_2 & 0xff0000);
	if (res > (R | G | B))
		res = R + (res & (G | B));
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
