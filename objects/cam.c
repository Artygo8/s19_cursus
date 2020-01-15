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
	t_vect	up;

	up.x = 0;
	up.y = 0;
	up.z = 1;
	cam->id = 1;
	cam->pos = ft_atovect(line);
	line += ft_next_arg(line);
	cam->dir = ft_atovect(line);
	line += ft_next_arg(line);
	cam->dist = ft_atof(line);
	cam->right = ft_vect_uni(ft_cross_prod(cam->dir, up));
	if (ft_vect_len(cam->right) < 0.0001)
	{
		up.y = 1;
		up.z = 0;
		cam->right = up;
	}
	cam->top = ft_cross_prod(cam->right, cam->dir);
	cam->top = ft_vect_uni(cam->top);
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
