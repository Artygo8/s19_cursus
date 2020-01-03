#include "../minirt.h"

/*
 * Get a int from the 3 values, RGB.
 * and other transformations.
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
 * Multiplies the rgb values by a constant.
 */

t_rgb	ft_mult_rgb(t_rgb rgb, float m)
{
	rgb.r *= m;
	rgb.g *= m;
	rgb.b *= m;
	return (rgb);
}

int		ft_mult_color(int color, float m)
{
	return (ft_rgb_color(ft_mult_rgb(ft_color_rgb(color), m)));
}

/*
 * Adds colors to one another.
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
 * Applies a colored light.
 */

t_rgb	ft_enlight_rgb(t_rgb rgb, t_rgb light)
{
	rgb.r *= (light.r / 256);
	rgb.g *= (light.g / 256);
	rgb.b *= (light.b / 256);
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
