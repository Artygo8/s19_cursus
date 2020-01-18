/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:26 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:43:28 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_init_cam(t_cam *cam, char *line)
{
	static int	id;
	t_vect		up;

	cam->pos = ft_atovect(line);
	line += ft_next_arg(line);
	cam->dir = ft_v_uni(ft_atovect(line));
	line += ft_next_arg(line);
	cam->dist = ft_atof(line);
	up = ft_v_init(0,-1,0);
	cam->id = ++id;
	if (ft_v_len(cam->dir) < EPS)
		cam->dir = ft_v_init(0,0,1);
	cam->right = ft_v_uni(ft_cross(cam->dir, up));
	if (ft_v_len(cam->right) < EPS)
		cam->right = ft_v_init(0,1,0);
	cam->top = ft_cross(cam->right, cam->dir);
	cam->top = ft_v_uni(cam->top);
}

void	ft_cam_res(t_cam *cam, char *line)
{
	cam->size_x = ft_atoi(line);
	if (cam->size_x > 2560)
		cam->size_x = 2560;
	line += ft_next_arg(line);
	cam->size_y = ft_atoi(line);
	if (cam->size_y > 1440)
		cam->size_y = 1440;
}
