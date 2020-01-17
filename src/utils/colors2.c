/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:21:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/08 19:21:25 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** Adds colors to one another.
*/

t_rgb	ft_add_rgb(t_rgb rgb_1, t_rgb rgb_2)
{
	t_rgb res;

	res.r = rgb_1.r + rgb_2.r;
	res.g = rgb_1.g + rgb_2.g;
	res.b = rgb_1.b + rgb_2.b;
	if (res.r > 255)
		res.r = 255;
	if (res.g > 255)
		res.g = 255;
	if (res.b > 255)
		res.b = 255;
	return (res);
}

int		ft_add_color(int color_1, int color_2)
{
	t_rgb rgb_1;
	t_rgb rgb_2;

	rgb_1 = ft_color_rgb(color_1);
	rgb_2 = ft_color_rgb(color_2);
	return (ft_rgb_color(ft_add_rgb(rgb_1, rgb_2)));
}

/*
** Applies a colored light.
*/

t_rgb	ft_enlight_rgb(t_rgb rgb, t_rgb light)
{
	rgb.r *= ((double)light.r / 256);
	rgb.g *= ((double)light.g / 256);
	rgb.b *= ((double)light.b / 256);
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

int		ft_enlight_color(int color, int light)
{
	t_rgb rgb_color;
	t_rgb rgb_light;

	rgb_color = ft_color_rgb(color);
	rgb_light = ft_color_rgb(light);
	return (ft_rgb_color(ft_enlight_rgb(rgb_color, rgb_light)));
}
