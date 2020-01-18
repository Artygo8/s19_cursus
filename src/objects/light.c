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
	light.color = ft_atocol(line);
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
	t_mat	mat;
	t_mat	tmp;

	mat.dist = INFINITY;
	while ((*objs).id)
	{
		tmp = (*objs).fct((*objs), ray);
		if (tmp.dist > EPS && tmp.dist < mat.dist)
			mat = tmp;
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
			ray = ft_ray(tab[j][i].pos, light.pos);
			if (ft_dot(tab[j][i].norm, ray.dir) > 0 &&
			ft_closest_obj(objs, ray).dist > ft_v_dist(ray.ori, light.pos))
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
					ft_enlight(tab[j][i].color, light.color,
					ft_dot(tab[j][i].norm, ray.dir) * light.percent
					/ pow(ft_v_dist(tab[j][i].pos, light.pos), 1 / 2)));
			i++;
		}
		j++;
	}
}

void	ft_put_ambi(t_cam cam, t_light light, t_mat **tab)
{
	int		j;
	int		i;

	j = 0;
	while (j < cam.size_y)
	{
		i = 0;
		while (i < cam.size_x)
		{
			tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
			ft_enlight(tab[j][i].color, light.color, light.percent));
			i++;
		}
		j++;
	}
}
