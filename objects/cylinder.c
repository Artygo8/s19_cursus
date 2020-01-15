/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:45:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:11 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_obj	ft_init_cyl(char *line, int id)
{
	t_obj object;

	object.id = id;
	object.fct = ft_axis_cyl;
	object.v1 = ft_vect_uni(ft_atovect(line));//center
	line += ft_next_arg(line);
	object.v2 = ft_vect_uni(ft_atovect(line));//direction
	line += ft_next_arg(line);
	object.d1 = ft_atof(line);
	line += ft_next_arg(line);
	object.d2 = ft_atof(line);
	line += ft_next_arg(line);
	object.color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

t_mat	ft_axis_cyl(t_obj cyl, t_line line)
{
	t_vect	eq;
	double	sol;
	t_mat	mat;
	double	mult;

	eq = (t_vect){
		pow(ft_vect_len(line.dir), 2) - pow(ft_dot_prod(line.dir, cyl.v2), 2),
		2 * (ft_dot_prod(line.dir, ft_vect_sub(line.point, cyl.v1)) -
		(ft_dot_prod(line.dir, cyl.v2) * ft_dot_prod(ft_vect_sub(line.point, cyl.v1), cyl.v2))),
		ft_dot_prod(ft_vect_sub(line.point, cyl.v1),ft_vect_sub(line.point, cyl.v1))
		- pow(ft_dot_prod(ft_vect_sub(line.point, cyl.v1), cyl.v2), 2) - cyl.d1 *cyl.d1
	};
	sol = ft_quad_solv(eq.x, eq.y, eq.z);
	mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
	mult = ft_dot_prod(line.dir, cyl.v2) * sol + ft_dot_prod(ft_vect_sub(line.point, cyl.v1), cyl.v2);
	mat.norm = ft_vect_uni(ft_vect_sub(ft_vect_sub(mat.pos, cyl.v1), ft_vect_mult(cyl.v2, mult)));
	if (ft_dot_prod(line.dir, mat.norm) > 0)
		mat.norm = ft_vect_mult(mat.norm, -1);
	mat.dist = ft_vect_dist(line.point, mat.pos);
	mat.color = cyl.color;
	mat.pxl = 0;
	if (sol <= 0)
		mat.dist = -1;
	return (mat);
}
