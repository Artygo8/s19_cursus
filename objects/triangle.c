/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:45:00 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_obj	ft_init_tri(char *line, int id)
{
	t_obj object;

	object.id = id;
	object.fct = ft_axis_tri;
	object.v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object.v2 = ft_atovect(line);
	line += ft_next_arg(line);
	object.v3 = ft_atovect(line);
	line += ft_next_arg(line);
	object.color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

t_mat	ft_axis_tri(t_obj tr, t_line line)
{
	double	sol;
	t_mat	mat;
	t_vect	n;

	n = ft_cross_prod(ft_vect_sub(tr.v2, tr.v1), ft_vect_sub(tr.v3, tr.v1));
	sol = ft_dot_prod(n, ft_vect_sub(tr.v1, line.point))
			/ ft_dot_prod(n, line.dir);
	mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
	mat.norm = ft_vect_uni(n);
	if (ft_dot_prod(line.dir, mat.norm) > 0)
		mat.norm = ft_vect_mult(mat.norm, -1);
	mat.dist = ft_vect_dist(line.point, mat.pos);
	mat.color = tr.color;
	mat.pxl = 0;
	if (!((ft_dot_prod(ft_cross_prod(ft_vect_sub(tr.v2, tr.v1),
		ft_vect_sub(mat.pos, tr.v1)), n) > 0)
		&& (ft_dot_prod(ft_cross_prod(ft_vect_sub(tr.v3, tr.v2),
		ft_vect_sub(mat.pos, tr.v2)), n) > 0)
		&& (ft_dot_prod(ft_cross_prod(ft_vect_sub(tr.v1, tr.v3),
		ft_vect_sub(mat.pos, tr.v3)), n) > 0)) || sol <= 0
		|| !ft_vect_len(n) || ft_dot_prod(n, line.dir) == 0)
		mat.dist = -1;
	return (mat);
}
