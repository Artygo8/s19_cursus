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

t_vect		ft_vect_add(t_vect v1, t_vect v2)
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

t_vect		ft_vect_sub(t_vect v1, t_vect v2)
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

t_vect		ft_vect_mult(t_vect v, double d)
{
	t_vect	new;

	new.x = v.x * d;
	new.y = v.y * d;
	new.z = v.z * d;
	return (new);
}

/*
** Gets a unitary vector from a vector.
*/

t_vect		ft_vect_uni(t_vect v)
{
	double l;

	l = ft_vect_len(v);
	if (l > 0.000001)
		return (ft_vect_mult(v, 1 / ft_vect_len(v)));
	else
		return (v);
}
