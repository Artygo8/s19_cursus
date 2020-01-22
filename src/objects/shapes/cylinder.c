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

#include "../../minirt.h"

/*
** All objects share the same structure.
** v1 is the Origin Point.
** v2 is the Direction.
** d1 is the Radius.
** d2 is the Length.
** returns NULL if allocation fails || if the format is not perfect
*/

t_obj	*ft_init_cyl(char *line)
{
	t_obj *object;
	int		valid;

	valid = 1;
	if (!(object = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	ft_bzero(object, sizeof(t_obj));
	object->fct = ft_axis_cyl;
	object->v1 = ft_atovect(line);
	valid &= ft_isvect(line);
	object->v2 = ft_v_uni(ft_atovect((line += ft_next_arg(line))));
	valid &= ft_isvect(line);
	object->d1 = ft_atof((line += ft_next_arg(line))) / 2;
	valid &= ft_isfloat(line);
	object->d2 = ft_atof((line += ft_next_arg(line)));
	valid &= ft_isfloat(line);
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

	if (sol < EPS)
		return (0);
	pos = ft_v_add(line.ori, ft_v_mult(line.dir, sol));
	if (ft_v_dist(pos, cyl.v1) > sqrt(pow(cyl.d1, 2) + pow(cyl.d2, 2)))
		return (0);
 	if (ft_dot(ft_v_sub(pos, cyl.v1), cyl.v2) < 0)
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

	vx = ft_v_sub(line.ori, cyl.v1);
	a = ft_dot(line.dir, line.dir) - pow(ft_dot(line.dir, cyl.v2), 2);
	b = 2 * ((ft_dot(line.dir, vx) -
		(ft_dot(line.dir, cyl.v2) * ft_dot(vx, cyl.v2))));
	c = ft_dot(vx, vx) - pow(ft_dot(vx, cyl.v2), 2) - cyl.d1 *cyl.d1;
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

	vx = ft_v_sub(line.ori, cyl.v1);
	m = ft_dot(line.dir, cyl.v2) * sol + ft_dot(vx, cyl.v2);
	norm = ft_v_sub(ft_v_sub(pos, cyl.v1), ft_v_mult(cyl.v2, m));
	norm = ft_v_uni(norm);
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
	mat.pos = ft_v_add(line.ori, ft_v_mult(line.dir, sol));
	mat.norm = ft_cyl_norm(cyl, line, mat.pos, sol);
	if (ft_dot(line.dir, mat.norm) > 0)
		mat.norm = ft_v_mult(mat.norm, -1);
	mat.dist = ft_v_dist(line.ori, mat.pos);
	mat.color = cyl.color;
	mat.pxl = 0;
	return (mat);
}
