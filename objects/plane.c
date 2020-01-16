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

#include "../minirt.h"

/*
** All objects share the same structure.
** v1 is a Point of the plane.
** v2 is the Normal Vector.
*/

t_obj	ft_init_plane(char *line, int id)
{
	t_obj object;

	object.id = id;
	object.fct = ft_axis_plane;
	object.v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object.v2 = ft_atovect(line);
	line += ft_next_arg(line);
	object.color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

t_mat	ft_axis_plane(t_obj pl, t_line line)
{
	double	sol;
	t_mat	mat;

	sol = ft_dot_prod(pl.v2, ft_vect_sub(pl.v1, line.point))
			/ ft_dot_prod(pl.v2, line.dir);
	if (sol > 0 && ft_dot_prod(pl.v2, line.dir) != 0)
	{
		mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
		mat.norm = ft_vect_uni(pl.v2);
		if (ft_dot_prod(line.dir, mat.norm) > 0)
			mat.norm = ft_vect_mult(mat.norm, -1);
		mat.dist = ft_vect_dist(line.point, mat.pos);
		mat.color = pl.color;
		mat.pxl = 0;
	}
	else
		mat.dist = -1;
	return (mat);
}
