/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:46:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:46:31 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_place_objects(t_obj *objs, t_cam cam, t_mat **tab)
{
	while ((*objs).id)
	{
		ft_obj_in_tab(*objs, cam, tab);
		objs++;
	}
}

void ft_obj_in_tab(t_obj s, t_cam cam, t_mat **tab)
{
	t_line	axis;
	t_mat	tmp;
	int		i;
	int		j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i].dist != -1)
		{
			axis = ft_ray(cam.pos, tab[j][i].pos);
			tmp = s.fct(s, axis);
			if (tmp.dist > 0 && tmp.dist < tab[j][i].dist)
				tab[j][i] = tmp;
			i++;
		}
		j++;
	}
}

t_vect	ft_screen(t_cam cam, int i, int j)
{
	t_vect v;

	v = ft_v_mult(cam.dir, cam.dist);
	v = ft_v_add(v, ft_v_mult(cam.top, ((float)j - (float)cam.size_y/2)));
	v = ft_v_add(v, ft_v_mult(cam.right, ((float)i - (float)cam.size_x/2)));
	return (ft_v_add(v, cam.pos));
}

t_mat	**ft_init_tab(t_cam cam, int color)
{
	t_mat	**tab;
	int		i;
	int		j;

	j = 0;
	if (!(tab = (t_mat**)malloc((cam.size_y + 1) * sizeof(t_mat*))))
		return (NULL);
	while (j < cam.size_y)
	{
		i = 0;
		if (!(tab[j] = (t_mat*)malloc((cam.size_x + 1) * sizeof(t_mat))))
			return (NULL);
		while (i < cam.size_x)
			tab[j][i++] = ft_init_mat(ft_screen(cam, i, j), INFINITY, color);
		tab[j++][i] = ft_init_mat(ft_screen(cam, i, j), -1, color);
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_put_tab(t_data data, t_mat **tab)
{
	int i;
	int j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i].dist >= 0)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, tab[j][i].pxl);
			i++;
		}
		j++;
	}
}
