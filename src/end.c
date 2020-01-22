#include "minirt.h"

void ft_free_tab(t_mat **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

void ft_free_data(t_data *data)
{
	ft_lstclear(&(data->objs), free);
	ft_lstclear(&(data->cams), free);
	ft_lstclear(&(data->lights), free);
	ft_free_tab(data->tab);
	free(data->mlx_ptr);
	free(data->mlx_win);
	free(data);
	data = NULL;
	exit(0);
}
