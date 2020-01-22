/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:45:20 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:21 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
** All objects share the same structure.
** v1 is a Point of the plane.
** v2 is the Normal Vector.
** returns NULL if allocation fails || if the format is not perfect
*/

t_obj	*ft_init_plane(char *line)
{
	t_obj *object;
	int		valid;

	valid = 1;
	if (!(object = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	ft_bzero(object, sizeof(t_obj));
	object->fct = ft_axis_plane;
	object->v1 = ft_atovect(line);
	valid &= ft_isvect(line);
	object->v2 = ft_atovect((line += ft_next_arg(line)));
	valid &= ft_isvect(line);
	object->color = ft_atocol((line += ft_next_arg(line)));
	valid &= ft_isrgb(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	if (!valid)
	{
		free(object);
		return (NULL);
	}
	return (object);
}

t_mat	ft_axis_plane(t_obj pl, t_line line)
{
	double	sol;
	t_mat	mat;

	sol = ft_dot(pl.v2, ft_v_sub(pl.v1, line.ori)) / ft_dot(pl.v2, line.dir);
	if (sol > 0 && ft_dot(pl.v2, line.dir) != 0)
	{
		mat.pos = ft_v_add(line.ori, ft_v_mult(line.dir, sol));
		mat.norm = ft_v_uni(pl.v2);
		if (ft_dot(line.dir, mat.norm) > 0)
			mat.norm = ft_v_mult(mat.norm, -1);
		mat.dist = ft_v_dist(line.ori, mat.pos);
		mat.color = pl.color;
		mat.pxl = 0;
	}
	else
		mat.dist = -1;
	return (mat);
}
