/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:59:02 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/29 16:59:04 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vect	ft_refl(t_vect inc, t_vect norm)
{
	t_vect ref;

	ref = ft_v_add(inc, ft_v_mult(norm, 2 * ft_dot(ft_v_mult(inc, -1), norm)));
	return (ft_v_uni(ref));
}

void	ft_specular(t_list *objs, t_cam *cam, t_light *light, t_mat **tab)
{
	t_vect	ref;
	t_line	ray;
	int		i;
	int		j;

	j = -1;
	while (++j < cam->size_y)
	{
		i = -1;
		while (++i < cam->size_x)
		{
			ray = ft_ray(tab[j][i].pos, light->pos);
			ref = ft_refl(ft_v_mult(ray.dir, -1), tab[j][i].norm);
			if (ft_dot(tab[j][i].norm, ray.dir) > 0 && ft_dot(ref,
				ft_v_mult(cam->dir, -1)) > 0 &&
			ft_closest_obj(objs, ray).dist > ft_v_dist(ray.ori, light->pos))
			{
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl,
					ft_mult_color(light->color, light->percent *
					pow(ft_dot(ref, ft_v_mult(cam->dir, -1)), SPECULAR)));
			}
		}
	}
}
