#include "../minirt.h"

t_light	*ft_init_light(char *line, int type)
{
	t_light *light;

	light->type = type;
	if (type == 'l')
	{
		light->pos = ft_atovect(line);
		line += ft_next_arg(line);
	}
	light->percent = ft_atof(line);
	line += ft_next_arg(line);
	light->color = ft_rgb_color(ft_atorgb(line));
	return (light);
}

void ft_put_light(t_cam cam, t_vect center, t_mat **tab)
{
	t_line ray;
	int i;
	int j;

	j = 0;
	while(j < cam.size_y)
	{
		i = 0;
		while (i < cam.size_x)
		{
			ray = (t_line){center, ft_vect_uni(ft_vect_sub(tab[j][i].pos, center))};
			if (ft_dot_prod(tab[j][i].norm, ray.dir) < 0) //parce aue le rayon incident est oppose a la normale
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl, ft_mult_color(tab[j][i].color, -ft_dot_prod(tab[j][i].norm, ray.dir)));
			i++;
		}
		j++;
	}
}

void ft_put_ambi(t_cam cam, t_mat **tab, double percent, int taint)
{
	t_line ray;
	int i;
	int j;

	j = 0;
	while(j < cam.size_y)
	{
		i = 0;
		while (i < cam.size_x)
		{
			if (tab[j][i].color)
				tab[j][i].pxl = ft_add_color(tab[j][i].pxl, ft_mult_color(taint, percent));
			i++;
		}
		j++;
	}
}
