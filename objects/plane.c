#include "../minirt.h"

t_obj	*ft_init_plane(char *line, int id)
{
	t_obj *object;

	object->id = id;
	object->type = Plane;
//	object->fct = ft_axis_plane;
	object->v1 = ft_atovect(line);
	line += ft_next_arg(line);
	object->v2 = ft_atovect(line);
	line += ft_next_arg(line);
	object->color = ft_rgb_color(ft_atorgb(line));
	return (object);
}
