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

#include "../minirt.h"

void	ft_place_objects(t_data *data, t_cam *cam, t_mat **tab)
{
	t_list *obj;

	obj = data->objs;
	while (obj)
	{
		ft_obj_in_tab(*((t_obj*)obj->content), *cam, tab);
		obj = obj->next;
	}
}

void	ft_obj_in_tab(t_obj s, t_cam cam, t_mat **tab)
{
	t_line	axis;
	t_mat	tmp;
	int		i;
	int		j;

	j = cam.size_y;
	while (j--)
	{
		i = cam.size_x;
		while (i--)
		{
			axis = ft_ray(cam.pos, tab[j][i].pos);
			tmp = s.fct(s, axis);
			if (tmp.dist > 0 && tmp.dist < tab[j][i].dist)
				tab[j][i] = tmp;
		}
	}
}

t_mat	**ft_init_tab(t_cam cam)
{
	t_mat	**tab;
	int		i;
	int		j;

	if (!(tab = (t_mat**)malloc((cam.size_y + 1) * sizeof(t_mat*))))
		return (NULL);
	j = cam.size_y;
	while (j--)
	{
		if (!(tab[j] = (t_mat*)malloc((cam.size_x + 1) * sizeof(t_mat))))
		{
			ft_free_tab(tab, j);
			return (NULL);
		}
		ft_bzero(tab[j], sizeof(t_mat));
		i = cam.size_x;
		while (i--)
			tab[j][i] = ft_init_mat(ft_screen(cam, i, j));
		tab[j][i].id = -1;
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_put_tab(t_data data, t_mat **tab)
{
	int i;
	int j;

	j = data.res_y;
	while (j--)
	{
		i = data.res_x;
		while (i--)
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j,
			ft_enlight(ft_mult_color(tab[j][i].pxl,
			(cos((float)j / data.res_y * PI * SINH) + 1) / 2
			* (cos((float)i / data.res_x * PI * SINV) + 1) / 2
			* ((cos((pow((float)(i - data.res_x / 2) / data.res_x * 2, 2) +
			pow((float)(j - data.res_y / 2) / data.res_y * 2, 2)) * PI * SINC)
			+ 1) / 2)), (RAINBOW) ? ft_rainbow((float)i / data.res_x) : 0xffffff, 1));
	}
}
