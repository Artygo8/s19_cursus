#include "../minirt.h"

t_obj	*ft_init_sphere(char *line, int id)
{
	t_obj *object;

	object->id = id;
	object->type = Sphere;
	object->fct = ft_axis_sphere;
	object->v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object->d1 = ft_atof(line);
	line += ft_next_arg(line);
	object->color = ft_rgb_color(ft_atorgb(line));
	return (object);
}

t_mat	ft_axis_sphere(t_obj s, t_line line)
{
	t_vect	eq;
	double	sol;
	t_mat	mat;
	t_vect	test = {1/sqrt(18), 1/sqrt(18), 4/sqrt(18)};

	eq = (t_vect){pow(ft_vect_len(line.dir), 2), 2 * ft_dot_prod(line.dir,
		ft_vect_sub(line.point, s.v1)),
		pow(ft_vect_len(s.v1), 2) + pow(ft_vect_len(line.point), 2)
		- 2 * (ft_dot_prod(s.v1, line.point)) - pow(s.d1, 2)};
	sol = ft_quad_solv(eq.x, eq.y, eq.z);
	if (sol)
	{
		mat.pos = ft_vect_add(line.point, ft_vect_mult(line.dir, sol));
		mat.norm = ft_vect_uni(ft_vect_sub(mat.pos, s.v1));
		mat.dist = ft_vect_dist(line.point, mat.pos);
		mat.color = s.color;
		mat.pxl = 0;
	}
	else
		mat.dist = -1;
	return (mat);
}
