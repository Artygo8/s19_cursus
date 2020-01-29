/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:44:51 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:44:52 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
** All objects share the same structure.
** v1 is the Center of the sphere.
** d1 is the Radius.
*/

t_obj	*ft_init_sphere(char *line)
{
	t_obj	*object;
	int		valid;

	valid = 1;
	if (!(object = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	ft_bzero(object, sizeof(t_obj));
	object->fct = ft_axis_sphere;
	object->v1 = ft_atovect(line);
	valid &= ft_isvect(line);
	object->d1 = ft_atof((line += ft_next_arg(line))) / 2;
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

t_mat	ft_axis_sphere(t_obj s, t_line line)
{
	t_vect	eq;
	double	sol;
	t_mat	mat;

	eq = (t_vect){pow(ft_v_len(line.dir), 2), 2 * ft_dot(line.dir,
		ft_v_sub(line.ori, s.v1)),
		pow(ft_v_len(s.v1), 2) + pow(ft_v_len(line.ori), 2)
		- 2 * (ft_dot(s.v1, line.ori)) - pow(s.d1, 2)};
	sol = ft_quad_solv(eq.x, eq.y, eq.z);
	mat.pos = ft_v_add(line.ori, ft_v_mult(line.dir, sol));
	mat.norm = ft_v_uni(ft_v_sub(mat.pos, s.v1));
	if (ft_dot(line.dir, mat.norm) > 0)
		mat.norm = ft_v_mult(mat.norm, -1);
	mat.dist = ft_v_dist(line.ori, mat.pos);
	mat.color = s.color;
	if (RAINBOW)
		mat.color = ft_rainbow((ft_dot(mat.norm, (t_vect){0, -1, 0}) + 1) / 2);
	mat.pxl = 0;
	if (sol <= 0)
		mat.dist = -1;
	return (mat);
}
