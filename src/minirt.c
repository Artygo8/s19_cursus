/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:47:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:47:13 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



void ft_tab_rt(t_cam *cams, int id, t_light *lights, t_obj *objs)
{
	t_data		data;
	t_mat		**tab;
	int			i;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cams[0].size_x,
		cams[0].size_y, "Hello world")) == NULL)
		return ;
	tab = ft_init_tab(cams[id], 0);
	ft_place_objects(objs, cams[id], tab);
	ft_put_lights(objs, cams[id], lights, tab);
	ft_put_tab(data, tab);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	mlx_loop(data.mlx_ptr);
}

int	ft_minirt(char *file)
{
	t_cam *cams;
	t_light *lights;
	t_obj *objs;

	if (!(ft_init_rt(file, &cams, &lights, &objs)))
		return 0;
	ft_tab_rt(cams, 0, lights, objs);
	return (1);
}

int main(int argc, char const *argv[])
{
//	t_rgb count = ft_objs_number((char*)argv[1]);

	ft_minirt((char*)argv[1]);
//	printf("%d cameras \n", count.r);
//	printf("%d lights \n", count.g);
//	printf("%d objs \n", count.b);
	return 0;
}
