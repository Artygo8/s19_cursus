#include "minirt.h"

t_list	*ft_init(t_list **objects, t_list **lights, t_cam *cam, char *file)
{
	char		*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf("Error Reading file\n");
	objects = NULL;
	lights = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_fill_objects(line, objects, lights, cam);
		free(line);
	}
	ft_fill_objects(line, objects, lights, cam);
	free(line);
}

void	ft_fill_objects(char *line, t_list **obj, t_list **lights, t_cam *cam)
{
	static int id = 1;

	if (!line)
		return ;
	if (line[0] == 'R' && ft_isspace(line[1]))
		ft_cam_res(cam, &line[1]);
	else if (line[0] == 'A' && ft_isspace(line[1]))
		ft_lstadd_back(lights, ft_lstnew(ft_init_light(&line[1], 'A')));
	else if (line[0] == 'c' && ft_isspace(line[1]))
		ft_init_cam(cam, &line[1]);
	else if (line[0] == 'l' && ft_isspace(line[1]))
		ft_lstadd_back(lights, ft_lstnew(ft_init_light(&line[1], 'l')));
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		ft_lstadd_back(obj, ft_lstnew(ft_init_plane(&line[2], id)));
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		ft_lstadd_back(obj, ft_lstnew(ft_init_sphere(&line[2], id)));
	else if (line[0] == 's' && line[1] == 'q' && ft_isspace(line[2]))
		ft_lstadd_back(obj, ft_lstnew(ft_init_square(&line[2], id)));
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		ft_lstadd_back(obj, ft_lstnew(ft_init_cyl(&line[2], id)));
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		ft_lstadd_back(obj, ft_lstnew(ft_init_tri(&line[2], id)));
	id++;
}

int		ft_next_arg(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]) || line[i] == '.' || line[i] == ',')
		i++;
	return (i);
}
