/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:39:52 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/22 17:39:58 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_init_cam_sys(t_cam *cam)
{
	t_vect	up;

	up = (t_vect){0, -1, 0};
	if (ft_v_len(cam->dir) < EPS)
		cam->dir = (t_vect){0, 0, 1};
	cam->right = ft_v_uni(ft_cross(cam->dir, up));
	if (ft_v_len(cam->right) < EPS)
		cam->right = (t_vect){0, 1, 0};
	cam->top = ft_v_uni(ft_cross(cam->right, cam->dir));
}

t_cam	*ft_init_cam(char *line)
{
	t_cam	*cam;
	int		valid;

	valid = 1;
	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	ft_bzero(cam, sizeof(t_cam));
	cam->pos = ft_atovect(line);
	valid &= ft_isvect(line);
	cam->dir = ft_v_uni(ft_atovect((line += ft_next_arg(line))));
	valid &= ft_isvect(line);
	cam->dist = ft_atof((line += ft_next_arg(line)));
	if (cam->dist > 180 || cam->dist < 0)
		valid = 0;
	valid &= ft_isfloat(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	ft_init_cam_sys(cam);
	if (!valid)
	{
		free(cam);
		return (NULL);
	}
	return (cam);
}

void	ft_data_res(t_data *data, char *line)
{
	data->res_x = ft_atoi(line);
	if (data->res_x > 3200)
		data->res_x = 3200;
	line += ft_next_arg(line);
	data->res_y = ft_atoi(line);
	if (data->res_y > 1800)
		data->res_y = 1800;
}

void	ft_cam_ids(t_list *cams, int res_x, int res_y)
{
	static int id;
	float	d;

	if (cams)
	{
		((t_cam*)cams->content)->id = ++id;
		((t_cam*)cams->content)->size_x = res_x;
		((t_cam*)cams->content)->size_y = res_y;
		d = ((t_cam*)cams->content)->dist;
		((t_cam*)cams->content)->dist = res_x / (tan(d * PI / 360));
		ft_cam_ids(cams->next, res_x, res_y);
	}
}
