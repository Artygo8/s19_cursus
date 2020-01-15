/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:46:57 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:46:58 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_objs_counter(char *line, t_rgb *count)
{
	if (!line)
		return ;
	if (line[0] == 'A' && ft_isspace(line[1]))
		count->g++;
	else if (line[0] == 'c' && ft_isspace(line[1]))
		count->r++;
	else if (line[0] == 'l' && ft_isspace(line[1]))
		count->g++;
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		count->b++;
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		count->b++;
	else if (line[0] == 's' && line[1] == 'q' && ft_isspace(line[2]))
		count->b++;
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		count->b++;
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		count->b++;
}

t_rgb	ft_objs_number(char *file)
{
	static t_rgb	count;
	int				fd;
	char			*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (count);
	while (get_next_line(fd, &line))
	{
		ft_objs_counter(line, &count);
		free(line);
	}
	ft_objs_counter(line, &count);
	free(line);
	close(fd);
	return (count);
}

void	ft_fill_objs(char *line, t_obj **objs, t_light **lights, t_cam **cams, t_rgb *id)
{
	static int nb = 1;

	if (!line)
		return ;
	if (line[0] == 'R' && ft_isspace(line[1]))
		ft_cam_res(&(*cams)[0], &line[1]);
	else if (line[0] == 'c' && ft_isspace(line[1]))
		ft_init_cam(&(*cams)[id->r-- - 1], &line[1]);
	else if (line[0] == 'A' && ft_isspace(line[1]))
		(*lights)[id->g-- - 1] = ft_init_light(&line[1], 'A');
	else if (line[0] == 'l' && ft_isspace(line[1]))
		(*lights)[id->g-- - 1] = ft_init_light(&line[1], 'l');
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		(*objs)[id->b-- - 1] = ft_init_plane(&line[2], nb++);
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		(*objs)[id->b-- - 1] = ft_init_sphere(&line[2], nb++);
	else if (line[0] == 's' && line[1] == 'q' && ft_isspace(line[2]))
		(*objs)[id->b-- - 1] = ft_init_square(&line[2], nb++);
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		(*objs)[id->b-- - 1] = ft_init_cyl(&line[2], nb++);
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		(*objs)[id->b-- - 1] = ft_init_tri(&line[2], nb++);
}

/*
** ft_init_rt returns 0 if malloc or anything fails in this case we have to free
*/

int	ft_init_rt(char *file, t_cam **cams, t_light **lights, t_obj **objs)
{
	static t_rgb id;
	int		fd;
	char	*line;

	id = ft_objs_number(file);
	if (!(*cams = (t_cam*)malloc(sizeof(t_cam) * (id.r + 1)))
	|| !(*lights = (t_light*)malloc(sizeof(t_light) * (id.g + 1)))
	|| !(*objs = (t_obj*)malloc(sizeof(t_obj) * (id.b + 1))))
		return (0);
	(*cams)[id.r].id = 0;
	(*lights)[id.g].type = 0;
	(*objs)[id.b].id = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error Reading file\n", 1);
	while (get_next_line(fd, &line))
	{
		ft_fill_objs(line, objs, lights, cams, &id);
		free(line);
	}
	ft_fill_objs(line, objs, lights, cams, &id);
	free(line);
	(fd > 0) ? close(fd) : 0;
	return ((fd > 0) ? 1 : 0);
}

int		ft_next_arg(char *line)
{
	int i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	while (line && line[i] && (ft_isdigit(line[i])
	|| line[i] == '.' || line[i] == ',' || line[i] == '-'))
		i++;
	return (i);
}
