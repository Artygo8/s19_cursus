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
** Get a int from the 3 values, RGB.
** and other transformations.
*/

int		ft_rgb(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

int		ft_rgb_color(t_rgb rgb)
{
	return (rgb.r * 256 * 256 + rgb.g * 256 + rgb.b);
}

t_rgb	ft_color_rgb(int color)
{
	t_rgb rgb;

	rgb.r = color / (256 * 256);
	rgb.g = (color / 256) % 256;
	rgb.b = color % 256;
	return (rgb);
}

/*
** Multiplies the rgb values by a constant.
*/

t_rgb	ft_mult_rgb(t_rgb rgb, float m)
{
	rgb.r *= m;
	rgb.g *= m;
	rgb.b *= m;
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

int		ft_mult_color(int color, float m)
{
	return (ft_rgb_color(ft_mult_rgb(ft_color_rgb(color), m)));
}
