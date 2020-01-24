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

t_light	*ft_init_light(char *line)
{
	t_light *light;
	int		valid;

	valid = 1;
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (NULL);
	light->type = *line++;
	if (light->type == 'l')
	{
		light->pos = ft_atovect(line);
		valid &= ft_isvect(line);
		line += ft_next_arg(line);
	}
	light->percent = ft_atof(line);
	valid &= ft_isfloat(line);
	light->color = ft_atocol((line += ft_next_arg(line)));
	valid &= ft_isrgb(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	if (!valid)
	{
		free(light);
		return (NULL);
	}
	return (light);
}

void	ft_put_lights(t_data *data, t_cam *cam, t_mat **tab)
{
	t_list *light;

	light = data->lights;
	while (light)
	{
		if (((t_light*)light->content)->type == 'A')
			ft_put_ambi(cam, ((t_light*)light->content), tab);
		if (((t_light*)light->content)->type == 'l')
		{
			ft_put_light(data->objs, cam, ((t_light*)light->content), tab);
			ft_specular(data->objs, cam, ((t_light*)light->content), tab);
		}
		light = light->next;
	}
}

t_mat	ft_closest_obj(t_list *objs, t_line ray)
{
	t_mat	mat;
	t_mat	tmp;

	mat.dist = INFINITY;
	while (objs)
	{
		tmp = ((t_obj*)objs->content)->fct(*((t_obj*)objs->content), ray);
		if (tmp.dist > EPS && tmp.dist < mat.dist)
			mat = tmp;
		objs = objs->next;
	}
	return (mat);
}

void	ft_put_light(t_list *objs, t_cam *cam, t_light *light, t_mat **tab)
{
	t_line	ray;
	int		i;
	int		j;

	j = 0;
	while (j < cam->size_y)
	{
		i = 0;
		while (i < cam->size_x)
		{
			ray = ft_ray(tab[j][i].pos, light->pos);
			if (ft_dot(tab[j][i].norm, ray.dir) > 0 &&
			ft_closest_obj(objs, ray).dist > ft_v_dist(ray.ori, light->pos))
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
					ft_enlight(tab[j][i].color, light->color,
					ft_dot(tab[j][i].norm, ray.dir) * light->percent
					/ pow(ft_v_dist(tab[j][i].pos, light->pos), 1 / 2)));
			i++;
		}
		j++;
	}
}

void	ft_put_ambi(t_cam *cam, t_light *light, t_mat **tab)
{
	int		j;
	int		i;

	j = 0;
	while (j < cam->size_y)
	{
		i = 0;
		while (i < cam->size_x)
		{
			tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
			ft_enlight(tab[j][i].color, light->color, light->percent));
			i++;
		}
		j++;
	}
}
