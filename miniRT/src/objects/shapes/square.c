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

void	ft_init_sq_sys(t_obj *object)
{
	t_vect	up;

	up = (t_vect){0, -1, 0};
	if (ft_v_len(object->v2) < EPS)
		object->v2 = (t_vect){0, 0, 1};
	object->v3 = ft_v_uni(ft_cross(object->v2, up));
	if (ft_v_len(object->v3) < EPS)
		object->v3 = (t_vect){0, 1, 0};
}

t_obj	*ft_init_square(char *line)
{
	t_obj	*object;
	int		valid;

	valid = 1;
	if (!(object = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	ft_bzero(object, sizeof(t_obj));
	object->fct = ft_axis_square;
	object->v1 = ft_atovect(line);
	valid &= ft_isvect(line);
	object->v2 = ft_v_uni(ft_atovect((line += ft_next_arg(line))));
	valid &= ft_isvect(line);
	object->d1 = ft_atof((line += ft_next_arg(line)));
	valid &= ft_isfloat(line);
	object->color = ft_atocol((line += ft_next_arg(line)));
	valid &= ft_isrgb(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	ft_init_sq_sys(object);
	if (!valid)
	{
		free(object);
		return (NULL);
	}
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
