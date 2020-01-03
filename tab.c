#include "minirt.h"

void ft_obj_in_tab(t_obj s, t_cam cam, t_mat **tab)
{
	t_line axis;
	int i;
	int j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i].dist != -1)
		{
			axis = (t_line){cam.pos, ft_vect_uni(ft_vect_sub(tab[j][i].pos, cam.pos))}; //ATTENTION !
			if (s.fct(s, axis).dist > 0 && s.fct(s, axis).dist < tab[j][i].dist)
				tab[j][i] = s.fct(s, axis);
			i++;
		}
		j++;
	}
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
		{
			tab[j][i] = (t_mat){ft_vect_add(ft_vect_add(ft_vect_add(
				ft_vect_mult(cam.dir, cam.dist),
				ft_vect_mult(cam.top, ((float)j - (float)cam.size_y/2))),
				ft_vect_mult(cam.right, ((float)i - (float)cam.size_x/2))),
				cam.pos), {0, 0, 0}, INFINITY, 0, color};
	//		printf("j = %d, i = %d\ncam x = %f\ncam y = %f\ncam z = %f\n",j,i, tab[j][i].pos.x, tab[j][i].pos.y, tab[j][i].pos.z);
			i++;
		}
		tab[j][i] = (t_mat){{0, 0, 0}, {0, 0, 0}, -1, 0, color}; //negative value
		j++;
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
		while (tab[j][i].dist > 0)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, tab[j][i].pxl);
			i++;
		}
		j++;
	}
}
