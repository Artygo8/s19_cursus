#include "../minirt.h"
/*
t_cam	ft_init_cam(t_cam *cam, t_vect pos, t_vect dir, double dist)
{
	t_vect	right;
	t_vect	top;

	cam->pos = pos;
	cam->dir = dir;
	cam->dist = dist;
	right = ft_cross_prod(cam->dir, (t_vect){0,0,1});
	if (ft_vect_len(right) >= 0.0001)
		cam->right = ft_vect_uni(right);
	else
		cam->right = (t_vect){0,1,0};
	top = ft_cross_prod(cam->right, cam->dir);
	cam->top = ft_vect_uni(top);
	return (cam);
}
*/
void	ft_init_cam(t_cam *cam, char *line)
{
	t_vect	right;
	t_vect	top;

	cam->pos = ft_atovect(line);
	line += ft_next_arg(line);
	cam->dir = ft_atovect(line);
	line += ft_next_arg(line);
	cam->dist = ft_atof(line);
	right = ft_cross_prod(cam->dir, (t_vect){0,0,1});
	if (ft_vect_len(right) >= 0.0001)
		cam->right = ft_vect_uni(right);
	else
		cam->right = (t_vect){0,1,0};
	top = ft_cross_prod(cam->right, cam->dir);
	cam->top = ft_vect_uni(top);
}

void ft_cam_res(t_cam *cam, char *line)
{
	while (line && ft_isspace(*line))
		line++;
	cam->size_x = ft_atoi(line);
	line += ft_next_arg(line);
	cam->size_y = ft_atoi(line);
}
