

int	ft_bmp(t_data *data, char *file)
{
	int		fd;
	char	*name;

	ft_bzero(file + 10, 1);
	name = ft_strlcat(file, ".bmp", 15);
	if (!(data->tab = ft_init_tab(*((t_cam*)data->cams->content))))
		ft_free_data(data, "FAILED INIT TAB");
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		ft_free_data(data, "FAIL OPENING FILE IN WRITING MODE");
	free(name);
	ft_putstr_fd();
	{
		while
	}
	ft_free_data(data);
}
