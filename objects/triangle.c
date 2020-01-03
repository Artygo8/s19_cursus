#include "../minirt.h"

t_obj	*ft_init_tri(char *line, int id)
{
	t_obj *object;

	object->id = id;
	object->type = Cylinder;
//	object->fct = ft_axis_tri;
	object->v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object->v2 = ft_atovect(line);
	line += ft_next_arg(line);
	object->v3 = ft_atovect(line);
	line += ft_next_arg(line);
	object->color = ft_rgb_color(ft_atorgb(line));
	return (object);
}
