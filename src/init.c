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

t_list	*ft_lst_obj(char *line)
{
	t_list *lst;

	lst = ft_lstnew(NULL);
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		lst = ft_lstnew(ft_init_plane(&line[2]));
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		lst = ft_lstnew(ft_init_sphere(&line[2]));
	else if (line[0] == 's' && line[1] == 'q' && ft_isspace(line[2]))
		lst = ft_lstnew(ft_init_square(&line[2]));
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		lst = ft_lstnew(ft_init_cyl(&line[2]));
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		lst = ft_lstnew(ft_init_tri(&line[2]));
	return (lst);
}

int		ft_fill_objs(char *line, t_data *data)
{
	t_list *lst;

	if (!line)
		return (0);
	if (line[0] == 0)
		return (1);
	if (line[0] == 'R' && ft_isspace(line[1]))
	{
		ft_data_res(data, &line[1]);
		return (1);
	}
	if (line[0] == 'c' && ft_isspace(line[1]))
		ft_lstadd_back(&data->cams, (lst = ft_lstnew(ft_init_cam(&line[1]))));
	else if ((line[0] == 'A' || line[0] == 'l') && ft_isspace(line[1]))
		ft_lstadd_back(&data->lights, (lst = ft_lstnew(ft_init_light(line))));
	else
		ft_lstadd_back(&data->objs, (lst = ft_lst_obj(line)));
	if (!lst->content)
		return (0);
	return (1);
}

int		ft_init_rt(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		res;

	res = 1;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error Reading file\n", 1);
	while (get_next_line(fd, &line))
	{
		res &= ft_fill_objs(line, data);
		free(line);
	}
	res &= ft_fill_objs(line, data);
	free(line);
	(fd > 0) ? close(fd) : 0;
	return ((fd > 0 && res) ? 1 : 0);
}

int		ft_next_arg(char *line)
{
	int i;

	i = 0;
	while (line && ft_isspace(line[i]))
		i++;
	while (line && (ft_isdigit(line[i]) || ft_isinset(line[i], ".,-")))
		i++;
	return (i);
}
