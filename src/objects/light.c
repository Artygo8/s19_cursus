/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:44:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:44:41 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_light	ft_init_light(char *line, int type)
{
	t_light light;

	light.type = type;
	if (type == 'l')
	{
		light.pos = ft_atovect(line);
		line += ft_next_arg(line);
	}
	light.percent = ft_atof(line);
	line += ft_next_arg(line);
	light.color = ft_rgb_color(ft_atorgb(line));
	return (light);
}

void	ft_put_lights(t_obj *objs, t_cam cam, t_light *lights, t_mat **tab)
{
	while ((*lights).type)
	{
		if ((*lights).type == 'A')
			ft_put_ambi(cam, *lights, tab);
		if ((*lights).type == 'l')
			ft_put_light(objs, cam, *lights, tab);
		lights++;
	}
}

t_mat	ft_closest_obj(t_obj *objs, t_line ray)
{
	t_mat mat;

	mat.dist = INFINITY;
	while ((*objs).id)
	{
		if ((*objs).fct((*objs), ray).dist > SMALL_DOUBLE
			&& (*objs).fct((*objs), ray).dist < mat.dist)
			mat = (*objs).fct((*objs), ray);
		objs++;
	}
	return (mat);
}

void	ft_put_light(t_obj *objs, t_cam cam, t_light light, t_mat **tab)
{
	t_line	ray;
	int		i;
	int		j;

	j = 0;
	while (j < cam.size_y)
	{
		i = 0;
		while (i < cam.size_x)
		{
			ray = (t_line){tab[j][i].pos,
				ft_vect_uni(ft_vect_sub(light.pos, tab[j][i].pos))};
			if (ft_dot_prod(tab[j][i].norm, ray.dir) > 0 && ft_closest_obj(objs,
				ray).dist > ft_vect_dist(tab[j][i].pos, light.pos))
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
					ft_enlight_color(tab[j][i].color, ft_mult_color(light.color,
					ft_dot_prod(tab[j][i].norm, ray.dir) * light.percent
					/ pow(ft_vect_dist(tab[j][i].pos, light.pos), 1 / 2))));
			i++;
		}
		j++;
	}
}

void	ft_put_ambi(t_cam cam, t_light light, t_mat **tab)
{
	t_line	ray;
	int		i;
	int		j;
	double	m;

	j = 0;
	while (j < cam.size_y)
	{
		i = 0;
		while (i < cam.size_x)
		{
			ray = (t_line){tab[j][i].pos,
				ft_vect_uni(ft_vect_sub(light.pos, tab[j][i].pos))};
			m = ft_dot_prod(tab[j][i].norm, ray.dir);
			m = (m > 0) ? m : -m;
			if (tab[j][i].color)
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
					ft_enlight_color(tab[j][i].color,
					ft_mult_color(light.color, light.percent * m
					)));
			i++;
		}
		j++;
	}
}
