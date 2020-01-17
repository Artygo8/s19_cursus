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

/*
** All objects share the same structure.
** v1 is the Origin Point.
** v2 is the Normal Vector.
** d1 is the General Radius.
** d2 is the Small Radius.
*/

t_obj	ft_init_tor(char *line, int id)
{
	t_obj object;

	object.id = id;
	object.fct = ft_axis_cyl;
	object.v1 = ft_vect_uni(ft_atovect(line));
	line += ft_next_arg(line);
	object.v2 = ft_vect_uni(ft_atovect(line));
	line += ft_next_arg(line);
	object.d1 = ft_atof(line) / 2;
	line += ft_next_arg(line);
	object.d2 = ft_atof(line) / 2;
	line += ft_next_arg(line);
	object.color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

/*
** Quadratic equation to implement :
** http://hugi.scene.org/online/hugi24/
** coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
** a   = D|D - (D|V)^2
** b/2 = D|X - (D|V)*(X|V)
** c   = X|X - (X|V)^2 - r*r
*/

int		ft_valid_sol_cyl(t_line line, t_obj cyl, double sol)
{
	t_vect pos;

	if (sol < SMALL_DOUBLE)
		return (0);
	pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
	if (ft_vect_dist(pos, cyl.v1) > sqrt(pow(cyl.d1, 2) + pow(cyl.d2, 2)))
		return (0);
 	if (ft_dot_prod(ft_vect_sub(pos, cyl.v1), cyl.v2) < 0)
		return (0);
	return (1);
}

double	ft_cyl_sol(t_obj cyl, t_line line)
{
	double a;
	double b;
	double c;
	t_vect	vx;
	double	sol;

	vx = ft_vect_sub(line.point, cyl.v1);
	a = ft_dot_prod(line.dir, line.dir) - pow(ft_dot_prod(line.dir, cyl.v2), 2);
	b = 2 * ((ft_dot_prod(line.dir, vx) -
		(ft_dot_prod(line.dir, cyl.v2) * ft_dot_prod(vx, cyl.v2))));
	c = ft_dot_prod(vx, vx) - pow(ft_dot_prod(vx, cyl.v2), 2) - cyl.d1 *cyl.d1;
	sol = ft_quad_solv(a, b, c);
	if (!(ft_valid_sol_cyl(line, cyl, sol)))
		sol = ft_quad_solv2(a, b, c);
	if (!(ft_valid_sol_cyl(line, cyl, sol)))
		sol = -1;
	return (sol);
}

/*
** Surface Normal is :
** m = D|V*t + X|V
** N = nrm( P-C-V*m )
*/

t_vect	ft_cyl_norm(t_obj cyl, t_line line, t_vect pos, double sol)
{
	double	m;
	t_vect	norm;
	t_vect	vx;

	vx = ft_vect_sub(line.point, cyl.v1);
	m = ft_dot_prod(line.dir, cyl.v2) * sol + ft_dot_prod(vx, cyl.v2);
	norm = ft_vect_sub(ft_vect_sub(pos, cyl.v1), ft_vect_mult(cyl.v2, m));
	norm = ft_vect_uni(norm);
	return (norm);
}

t_mat	ft_axis_cyl(t_obj cyl, t_line line)
{
	double	sol;
	t_mat	mat;
	double	mult;

	mat.dist = -1;
	sol = ft_cyl_sol(cyl, line);
	if (sol <= 0)
		return (mat);
	mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
	mat.norm = ft_cyl_norm(cyl, line, mat.pos, sol);
	if (ft_dot_prod(line.dir, mat.norm) > 0)
		mat.norm = ft_vect_mult(mat.norm, -1);
	mat.dist = ft_vect_dist(line.point, mat.pos);
	mat.color = cyl.color;
	mat.pxl = 0;
	return (mat);
}
