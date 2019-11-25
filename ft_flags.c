#include "ft_printf.h"

void		ft_flag_applier(t_inf *inf)
{
	char *tmp;

	ft_special_cases(inf);
	ft_point_flag_str(inf);
	if (inf->p >= 0 && ft_isinset(inf->cv, "diuxX%"))
		ft_point_flag_nbr(inf);
	if (inf->cv == 'p')
	{
		tmp = ft_strjoin("0x", inf->str);
		free(inf->str);
		inf->str = tmp;
	}
	if (inf->fw != 0)
		ft_space_flags(inf);
}

void 		ft_special_cases(t_inf *inf)
{
	char	*tmp;

	if (ft_isinset(inf->cv, "diuxX%"))
	{
		if (inf->p == 0 && inf->str[0] == '0')
		{
			tmp = ft_strdup("");
			free(inf->str);
			inf->str = tmp;
		}
		if (inf->p == -1)
			inf->p = (inf->str[0] == '-') ? inf->zeros - 1 : inf->zeros;
		else if (inf->p < inf->zeros + (inf->str[0] == '-'))
			inf->fw = inf->zeros;
	}
	if (inf->str == NULL && inf->cv == 's')
		inf->str = ft_strdup("(null)");
}

void		ft_point_flag_str(t_inf *inf)
{
	char	*tmp;
	int		i;

	if (inf->cv == 's' && inf->p >= 0)
	{
		i = 0;
		tmp = ft_substr(inf->str, 0, inf->p);
		free(inf->str);
		inf->str = tmp;
	}
}

/*
 * We dont care about undefined behaviors
 */

void		ft_point_flag_nbr(t_inf *inf)
{
	char	*s;
	int		i;

	i = 0;
	if (inf->p > ((int)ft_strlen(inf->str) - (inf->str[0] == '-')))
	{
		if (!(s = malloc(sizeof(char*) * (inf->p + (inf->str[0] == '-') + 1))))
			return ;
		if (inf->str[0] == '-')
			s[i++] = '-';
		while (inf->p-- > ((int)ft_strlen(inf->str)) - (inf->str[0] == '-'))
			s[i++] = '0';
		s[i] = '\0';
		s = ft_strjoin(s, &(inf->str[(inf->str[0] == '-')]));
		free(inf->str);
		inf->str = s;
	}
}

void		ft_space_flags(t_inf *inf)
{
	char	*tmp;
	int		i;
	int		abs;

	i = 0;
	abs = ((inf->fw > 0) ? inf->fw : -inf->fw);
	if (inf->zeros > abs)
		abs = inf->zeros;
	tmp = malloc(sizeof(char) * (abs + 1));
	if (!tmp)
		return ;
	while (abs-- > (int)ft_strlen(inf->str))
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (inf->fw > 0)
		tmp = ft_strjoin(tmp, inf->str);
	else
		tmp = ft_strjoin(inf->str, tmp);
	free(inf->str);
	inf->str = tmp;
}
