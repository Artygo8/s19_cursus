/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:45:31 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:33 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
** All objects share the same structure.
** v1 is the Center Point.
** v2 is the Normal Vector.
** v3 is a Vector Orthogonal to the normal vector coplanar with the square.
** d1 is the Height.
*/

t_obj	ft_init_square(char *line, int id)
{
	t_obj	object;
	t_vect	up;

	up = ft_v_init(0,-1,0);
	object.id = id;
	object.fct = ft_axis_square;
	object.v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object.v2 = ft_v_uni(ft_atovect(line));
	if (ft_v_len(object.v2) < EPS)
		object.v2 = ft_v_init(0,0,1);
	object.v3 = ft_v_uni(ft_cross(object.v2, up));
	if (object.v3.x == 0 && object.v3.y == 0 && object.v3.z == 0)
		object.v3 = ft_v_init(0,1,0);
	line += ft_next_arg(line);
	object.d1 = ft_atof(line);
	line += ft_next_arg(line);
	object.color = ft_atocol(line);
	return (object);
}

t_mat	ft_axis_square(t_obj sq, t_line line)
{
	double	sol;
	t_mat	mat;
	t_vect	v4;

	v4 = ft_v_uni(ft_cross(sq.v2, sq.v3));
	sol = ft_dot(sq.v2, ft_v_sub(sq.v1, line.ori))
			/ ft_dot(sq.v2, line.dir);
	mat.pos = ft_v_add(line.ori, ft_v_mult(line.dir, sol));
	mat.norm = ft_v_uni(sq.v2);
	if (ft_dot(line.dir, mat.norm) > 0)
		mat.norm = ft_v_mult(mat.norm, -1);
	mat.dist = ft_v_dist(line.ori, mat.pos);
	mat.color = sq.color;
	mat.pxl = 0;
	if (!(ft_dot(sq.v3, ft_v_sub(mat.pos, sq.v1)) < sq.d1 / 2
		&& ft_dot(sq.v3, ft_v_sub(mat.pos, sq.v1)) > -sq.d1 / 2
		&& ft_dot(v4, ft_v_sub(mat.pos, sq.v1)) < sq.d1 / 2
		&& ft_dot(v4, ft_v_sub(mat.pos, sq.v1)) > -sq.d1 / 2)
		|| sol <= 0 || ft_dot(sq.v2, line.dir) == 0)
		mat.dist = -1;
	return (mat);
}
