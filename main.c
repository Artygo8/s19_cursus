#include "minirt.h"

int main(int argc, char const *argv[])
{
	t_data		data;
	t_cam		cam;
	t_mat		**tab;
	t_list		*objects;
	t_list		*lights;

	ft_init(&objects, &lights, &cam, (char*)argv[1]);
	tab = ft_init_tab(cam, 0);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cam.size_x, cam.size_y, "Hello world")) == NULL)
		return (EXIT_FAILURE);
//	ft_place_objects(objects, cam, tab);
	ft_put_light(cam, (t_vect){0, -100, -100}, tab);
	ft_put_ambi(cam, tab, 0.05, 0xffffff);
	ft_put_tab(data, tab);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}


void	ft_place_objects(t_list *objects, t_cam cam, t_mat **tab)
{
	while (objects)
	{
//		ft_obj_in_tab(objects->content, cam, tab);
		objects = objects->next;
	}
}

/*
int		main(void)
{
	t_data		data;
	t_sphere	s = {100, {0, 0, 0}, 0xffffff}; //0xef86a8
	t_cam		cam;
	t_mat		**tab;

	cam = ft_init_cam((t_vect){0,0,-600}, (t_vect){0,0,1}, 600);
	ft_cam_res(&cam, 1000, 500);
	tab = ft_init_tab(cam, 0);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cam.size_x, cam.size_y, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	ft_obj_in_tab(s, cam, tab, ft_axis_sphere);
	ft_put_light(cam, (t_vect){0, -100, -100}, tab);
	ft_put_ambi(cam, tab, 0.05, 0xffffff);
	ft_put_tab(data, tab);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
*/
