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

#include "../minirt.h"

t_obj	ft_init_square(char *line, int id)
{
	t_obj	object;
	t_vect	up;

	up.x = 0;
	up.y = 0;
	up.z = 1;
	object.id = id;
	object.fct = ft_axis_square;
	object.v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object.v2 = ft_atovect(line);
	object.v3 = ft_vect_uni(ft_cross_prod(object.v2, up));
	if (object.v3.x == 0 && object.v3.y == 0 && object.v3.z == 0)
	{
		up.y = 1;
		up.z = 0;
		object.v3 = up;
	}
	line += ft_next_arg(line);
	object.d1 = ft_atof(line);
	line += ft_next_arg(line);
	object.color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

t_mat	ft_axis_square(t_obj sq, t_line line)
{
	double	sol;
	t_mat	mat;
	t_vect	v4;

	v4 = ft_vect_uni(ft_cross_prod(sq.v2, sq.v3));
	sol = ft_dot_prod(sq.v2, ft_vect_sub(sq.v1, line.point))
			/ ft_dot_prod(sq.v2, line.dir);
	mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
	mat.norm = ft_vect_uni(sq.v2);
	if (ft_dot_prod(line.dir, mat.norm) > 0)
		mat.norm = ft_vect_mult(mat.norm, -1);
	mat.dist = ft_vect_dist(line.point, mat.pos);
	mat.color = sq.color;
	mat.pxl = 0;
	if (!(ft_dot_prod(sq.v3, ft_vect_sub(mat.pos, sq.v1)) < sq.d1 / 2
		&& ft_dot_prod(sq.v3, ft_vect_sub(mat.pos, sq.v1)) > -sq.d1 / 2
		&& ft_dot_prod(v4, ft_vect_sub(mat.pos, sq.v1)) < sq.d1 / 2
		&& ft_dot_prod(v4, ft_vect_sub(mat.pos, sq.v1)) > -sq.d1 / 2)
		|| sol <= 0 || ft_dot_prod(sq.v2, line.dir) == 0)
		mat.dist = -1;
	return (mat);
}
