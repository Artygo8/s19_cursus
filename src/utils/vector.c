/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:21:45 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/08 19:21:47 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** Cross Product.
*/

t_vect		ft_cross(t_vect v1, t_vect v2)
{
	t_vect new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}

/*
** Dot Product.
*/

double		ft_dot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/*
** Length of a vector from the origin.
*/

double		ft_v_len(t_vect v)
{
	return (sqrt(ft_dot(v, v)));
}

/*
** Distance between 2 points.
*/

double		ft_v_dist(t_vect v1, t_vect v2)
{
	double x;
	double y;
	double z;

	x = (v2.x - v1.x);
	y = (v2.y - v1.y);
	z = (v2.z - v1.z);
	return (sqrt(x * x + y * y + z * z));
}

/*
** Normalized direction from one point to the other
*/

t_vect		ft_v_dir(t_vect v1, t_vect v2)
{
	return(ft_v_uni(ft_v_sub(v2, v1)));
}

t_line		ft_ray(t_vect origin, t_vect point)
{
	t_line ray;

	ray.ori = origin;
	ray.dir = ft_v_dir(origin, point);
	return (ray);
}
