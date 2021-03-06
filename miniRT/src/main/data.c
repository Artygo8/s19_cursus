/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:47:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/25 13:29:50 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_mat	**ft_free_tab(t_mat **tab, int res_y)
{
	int i;

	i = 0;
	while (tab && i < res_y)
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
//	free(tab); // for some reason, this free does not fail on MacOS but fails on linux.
	return (NULL);
}

void	ft_free_data(t_data *data, const char *str)
{
	ft_putstr_fd((char*)str, 1);
	ft_putchar_fd('\n', 1);
	ft_lstclear(&(data->objs), free);
	ft_lstclear(&(data->cams), free);
	ft_lstclear(&(data->lights), free);
	data->tab = ft_free_tab(data->tab, data->res_y);
	free(data->mlx_ptr);
	free(data->mlx_win);
	free(data);
	exit(0);
}

void	ft_show(t_data *data)
{
	t_list *tmp;

	if (!(data->tab = ft_init_tab(*((t_cam*)data->cams->content))))
		ft_free_data(data, "FAILED INIT TAB");
	ft_place_objects(data, (t_cam*)data->cams->content, data->tab);
	ft_put_lights(data, (t_cam*)data->cams->content, data->tab);
	ft_put_tab(*data, data->tab);
	tmp = (t_list *)(data->cams);
	data->cams = (data->cams)->next;
	free(tmp);
	data->tab = ft_free_tab(data->tab, data->res_y);
}

void	ft_obj_ids(t_list *objs)
{
	static int id;

	if (objs)
	{
		((t_cam*)objs->content)->id = ++id;
		ft_obj_ids(objs->next);
	}
}

t_data	*ft_data(char *file, int s)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (0);
	ft_bzero(data, sizeof(t_data));
	if (s == 1)
		if ((data->mlx_ptr = mlx_init()) == NULL)
			return (0);
	data->filter = 0xffffff;
	if (!(ft_init_rt(file, data)))
		ft_free_data(data, "PARSING FAILED");
	if (s == 1)
		if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_x,
			data->res_y, file)) == NULL)
			ft_free_data(data, "PARSING FAILED");
	ft_cam_ids(data->cams, data->res_x, data->res_y);
	ft_obj_ids(data->objs);
	return (data);
}
