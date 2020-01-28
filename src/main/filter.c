#include "../minirt.h"

int		ft_filter(t_data *data, char *line)
{
	int		valid;

	valid = 1;
	data->filter &= ft_atocol(line);
	valid &= ft_isrgb(line);
	valid &= (*(line + ft_next_arg(line)) == 0);
	return (valid);
}
