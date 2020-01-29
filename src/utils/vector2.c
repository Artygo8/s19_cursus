/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:21:52 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/08 19:21:54 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** Vectorial addition.
*/

t_vect		ft_v_add(t_vect v1, t_vect v2)
{
	t_vect new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

/*
** Vectorial substraction.
*/

t_vect		ft_v_sub(t_vect v1, t_vect v2)
{
	t_vect new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

/*
** Multiplication of a vector by a scalar.
*/

t_vect		ft_v_mult(t_vect v, double d)
{
	t_vect	new;

	new.x = v.x * d;
	new.y = v.y * d;
	new.z = v.z * d;
	return (new);
}

/*
** Gets a unitary vector from a vector.
** Doesnt try if the length of the vector is too small.
*/

t_vect		ft_v_uni(t_vect v)
{
	double l;

	l = ft_v_len(v);
	if (l > EPS)
		v = ft_v_mult(v, 1 / ft_v_len(v));
	return (v);
}

t_vect		ft_v_dir(t_vect v1, t_vect v2)
{
	return (ft_v_uni(ft_v_sub(v2, v1)));
}
