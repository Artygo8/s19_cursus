#include "../minirt.h"

/*
 * Cross Product.
 */

t_vect		ft_cross_prod(t_vect v1, t_vect v2)
{
	t_vect new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}

/*
 * Dot Product.
 */

double		ft_dot_prod(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/*
 * Length of a vector from the origin.
 */

double		ft_vect_len(t_vect v)
{
	return (sqrt(ft_dot_prod(v, v)));
}

/*
 * Distance between 2 points.
 */

double		ft_vect_dist(t_vect v1, t_vect v2)
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
 * Vectorial addition.
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
 * Vectorial substraction.
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
 * Multiplication of a vector by a scalar.
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
 * Gets a unitary vector from a vector.
 */

t_vect		ft_vect_uni(t_vect v)
{
	return (ft_vect_mult(v, 1 / ft_vect_len(v)));
}
