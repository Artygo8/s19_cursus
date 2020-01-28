#include "../minirt.h"

void	ft_putbuf_fd(unsigned int nb, int max, int fd)
{
	int i;

	i = 0;
	while (i < max)
		ft_putchar_fd(nb >> (i++ * 8), fd);
}

char *ft_bmp_name(char *file)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 0;
	name = ft_strdup(file);
	while (ft_strchr(name, '/'))
	{
		tmp = ft_strdup(ft_strchr(name, '/') + 1);
		free(name);
		name = tmp;
	}
	while (name[i] && name[i] != '.')
		i++;
	tmp = ft_substr(name, 0, i);
	free(name);
	name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	tmp = ft_strjoin("bmps/", name);
	free(name);
	return (tmp);
}

void ft_puttab_fd(t_mat **tab, int res_x, int res_y, int fd)
{
	int i;
	int j;

	j = res_y;
	while (j--)
	{
		i = -1;
		while (++i < res_x)
			ft_putbuf_fd(tab[j][i].pxl, 3, fd);
	}
}

int	ft_bmp(t_data *data, char *file)
{
	int		fd;
	char	*name;

	if (!(data->tab = ft_init_tab(*((t_cam*)data->cams->content))))
		ft_free_data(data, "FAILED INIT TAB");
	ft_place_objects(data, (t_cam*)data->cams->content, data->tab);
	ft_put_lights(data, (t_cam*)data->cams->content, data->tab);
	name = ft_bmp_name(file);
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		free(name);
		ft_free_data(data, "FAIL OPENING FILE IN WRITING MODE");
	}
	free(name);
	ft_putstr_fd("BM", fd);
	ft_putbuf_fd(3 * data->res_x * data->res_y + 54, 8, fd);
	ft_putbuf_fd(26, 4, fd);
	ft_putbuf_fd(12, 4, fd);
	ft_putbuf_fd(data->res_x + (data->res_y<<16), 4, fd);
	ft_putbuf_fd(1 + ((8 * 3)<<16), 4, fd);
	ft_puttab_fd(data->tab, data->res_x, data->res_y, fd);
	close(fd);
	ft_free_data(data, "Save Succeed");
	return (0);
}
