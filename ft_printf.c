#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	infos			*inf;
	char			*new_s;

	new_s = NULL;
	va_start(ap, format);
	inf = (infos*)malloc(sizeof(infos));
	while (*format)
	{
		ft_init_infos(inf);
		if (*format == '%')
			format += ft_process(&ap, (char *)format + 1, inf);
		new_s = ft_strjoin(new_s, inf->str);
		free(inf->str);
		if (!inf->str)
			new_s = ft_strjoin_char(new_s, *format);
		format++;
	}
	va_end(ap);
	ft_putstr_fd(new_s, 1);
	free(new_s);
	return (0);
}

void		ft_init_infos(infos *inf)
{
	inf->str = NULL;
	inf->cv = 0;
	inf->p = -1;
	inf->spaces = 0;
	inf->zeros = 0;
}

int			ft_process(va_list *ap, char *str, infos *inf)
{
	int i;

	i = 0;
	if (str[i] == '0')
		inf->zeros = ft_atoi_p(&str[i]);
	else if (str[i] == '*' || str[i] == '-' || ft_isdigit(str[i]))
		inf->spaces = ((str[i] == '*') ? va_arg(*ap, int) : ft_atoi_p(str));
	while (str[i] == '*' || str[i] == '-' || ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			inf->spaces = ft_atoi_p(&str[i]);
		i++;
	}
	if (str[i] == '.')
	{
		inf->p = 0;
		i++;
	}
	if (str[i] == '*' || ft_isdigit(str[i]))
		inf->p = ((str[i] == '*') ? va_arg(*ap, int) : ft_atoi_p(&str[i]));
	while (str[i] == '*' || ft_isdigit(str[i]))
		i++;
	if (ft_isconvert(str[i]))
		ft_convert(ap, str[i], inf);
	return ((ft_isconvert(str[i])) ? i + 1 : 0);
}

void		ft_convert(va_list *ap, char c, infos *inf)
{
	inf->cv = c;
	if (c == 'c')
		inf->str = ft_strdup_char(va_arg(*ap, int));
	else if (c == 's')
		inf->str = ft_strdup(va_arg(*ap, char*));
	if (c == 'd' || c == 'i')
		inf->str = ft_itoa(va_arg(*ap, int));
	else if (c == 'u')
		inf->str = ft_utoa_base(va_arg(*ap, int), BASE_TEN);
	else if (c == 'x')
		inf->str = ft_utoa_base(va_arg(*ap, int), X_MIN_BASE);
	else if (c == 'X')
		inf->str = ft_utoa_base(va_arg(*ap, int), X_MAJ_BASE);
	else if (c == '%')
		inf->str = ft_strdup_char('%');
	else if (c == 'p')
		inf->str = ft_utoa_base(va_arg(*ap, int), X_MAJ_BASE);
	ft_flag_applier(inf);
}

void		ft_flag_applier(infos *inf)
{
	char *tmp;

	if (inf->p == -1) /*WORKING ON IT*/
		inf->p = (inf->str[0] == '0') ? inf->zeros : inf->zeros - 1;
	if (inf->str == NULL)
		inf->str = ft_strdup("(null)");
	if (inf->cv == 's' && inf->p >= 0)
		ft_point_flag_str(inf);
	else if (inf->p >= 0 && inf->cv != 'c' && inf->cv != 's')
		ft_point_flag_nbr(inf);
	if (inf->cv == 'p')
	{
		tmp = ft_strjoin("0x", inf->str);
		free(inf->str);
		inf->str = tmp;
	}
	if (inf->spaces != 0)
		ft_space_flags(inf);
}

void		ft_point_flag_str(infos *inf)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_substr(inf->str, 0, inf->p);
	free(inf->str);
	inf->str = s;
}

void		ft_point_flag_nbr(infos *inf)
{
	char	*s;
	int		i;

	i = 0;
	if (inf->p == 0 && inf->str[0] == '0')
	{
		s = ft_strdup("");
		free (inf->str);
		inf->str = s;
	}
	else if (inf->p >= ((int)ft_strlen(inf->str) + ((inf->p == 'p') ? 2 : 0)))
	{
		if (!(s = malloc(sizeof(char*) * (inf->p + (inf->str[0] == '-') + 1))))
			return ;
		if (inf->str[0] == '-')
			s[i++] = '-';
		while (inf->p-- > ((int)ft_strlen(&(inf->str[(inf->str[0] == '-')])) +
													((inf->p == 'p') ? 2 : 0)))
			s[i++] = '0';
		s[i] = '\0';
		s = ft_strjoin(s, &(inf->str[(inf->str[0] == '-')]));
		free(inf->str);
		inf->str = s;
	}
}

void		ft_space_flags(infos *inf)
{
	char	*tmp;
	int		i;
	int		abs;

	i = 0;
	abs = ((inf->spaces > 0) ? inf->spaces : -inf->spaces);
	if (inf->zeros > abs)
		abs = inf->zeros;
	tmp = malloc(sizeof(char) * (abs + 1));
	if (!tmp)
		return ;
	while (abs-- > (int)ft_strlen(inf->str))
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (inf->spaces > 0)
		tmp = ft_strjoin(tmp, inf->str);
	else
		tmp = ft_strjoin(inf->str, tmp);
	free(inf->str);
	inf->str = tmp;
}

int			ft_isinset(char c, char *set)
{
	while (set && *set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
