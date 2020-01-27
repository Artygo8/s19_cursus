#include "../minirt.h"

void	ft_putcolor_fd(int color, int fd)
{
	ft_putchar_fd(color >> 16, fd);
	ft_putchar_fd(color >> 8, fd);
	ft_putchar_fd(color, fd);
}

void	ft_putint_fd(int nb, int fd)
{
	ft_putchar_fd((nb & ALPHA) >> 24, fd);
	ft_putchar_fd((nb & R) >> 16, fd);
	ft_putchar_fd((nb & G) >> 8, fd);
	ft_putchar_fd(nb & B, fd);
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
			ft_putcolor_fd(tab[j][i].pxl, fd);
	}
}

int	ft_bmp(t_data *data, char *file)
{
	int		i;
	int		fd;
	char	*name;

	i = 0;
	name = ft_bmp_name(file);
	if (!(data->tab = ft_init_tab(*((t_cam*)data->cams->content))))
		ft_free_data(data, "FAILED INIT TAB");
	ft_place_objects(data, (t_cam*)data->cams->content, data->tab);
	ft_put_lights(data, (t_cam*)data->cams->content, data->tab);
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		ft_free_data(data, "FAIL OPENING FILE IN WRITING MODE");
	ft_putstr_fd("BM", fd);
	ft_putint_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putint_fd(54, fd);
	ft_putint_fd(40, fd);
	ft_putint_fd(data->res_x, fd);
	ft_putint_fd(data->res_y, fd);
	ft_putcolor_fd(0, fd);
	ft_putint_fd(0x01001800, fd);
	while (i++ < 6)
		ft_putint_fd(0, fd);
	ft_puttab_fd(data->tab, data->res_x, data->res_y, fd);
	free(name);
	ft_free_data(data, "Save Succeed");
	return (0);
}
