#include "../minirt.h"

t_obj	*ft_init_cyl(char *line, int id)
{
	t_obj *object;

	object->id = id;
	object->type = Cylinder;
//	object->fct = ft_axis_cyl;
	object->v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object->v2 = ft_atovect(line);
	line += ft_next_arg(line);
	object->d1 = ft_atof(line);
	line += ft_next_arg(line);
	object->d2 = ft_atof(line);
	line += ft_next_arg(line);
	object->color = ft_rgb_color(ft_atorgb(line));
	return (object);
}
