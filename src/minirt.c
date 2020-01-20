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


/*
void ft_tab_rt(t_cam *cams, int id, t_light *lights, t_obj *objs)
{
	t_data		data;
	t_mat		**tab;
	int			i;

	if ((data->mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, cams[0].size_x,
		cams[0].size_y, "Hello world")) == NULL)
		return ;
	tab = ft_init_tab(cams[id], 0);
//	ft_place_objects(objs, cams[id], tab);
//	ft_put_lights(objs, cams[id], lights, tab);
//	ft_put_tab(data, tab);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	mlx_loop(data->mlx_ptr);
}
*/

void	ft_obj_ids(t_list *objs)
{
	static int id;

	if (objs)
	{
		((t_cam*)objs->content)->id = ++id;
		ft_obj_ids(objs->next);
	}
}

void ft_free_data(t_data *data)
{
	ft_lstclear(&(data->objs), free);
	ft_lstclear(&(data->cams), free);
	ft_lstclear(&(data->lights), free);
	free(data->mlx_ptr);
	free(data->mlx_win);
	free(data);
	data = NULL;
}

t_data	*ft_data(char *file) //ft_data
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return 0;
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return 0;
	if (!(ft_init_rt(file, data)))
	{
		ft_free_data(data);
		return 0;
	}
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_x,
		data->res_y, "Hello world")) == NULL)
	{
		ft_free_data(data);
		return 0;
	}
	ft_cam_ids(data->cams, data->res_x, data->res_y);
	ft_obj_ids(data->objs);
	return (data);
}

int	ft_minirt(char *file) //ft_data
{
	t_data *data;
	t_mat **tab;
	int i = 0;

	if (!(data = ft_data(file)))
	{
		ft_putstr_fd("PARSING ERROR\n", 1);
		return (0);
	}
	tab = ft_init_tab(*((t_cam*)data->cams->content));
	ft_place_objects(data, (t_cam*)data->cams->content, tab);
	ft_put_lights(data, (t_cam*)data->cams->content, tab);
	ft_put_tab(*data, tab);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	mlx_loop(data->mlx_ptr);
	return (0);
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
