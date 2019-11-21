#include "ft_printf.h"

void		ft_convert(va_list *ap, char c, infos *inf)
{
	inf->cv = c;
	if (c == 'c')
		inf->str = ft_strdup_char(va_arg(*ap, int));
	else if (c == 's')
		inf->str = ft_strdup(va_arg(*ap, char*));
	else if (c == 'd' || c == 'i')
		inf->str = ft_itoa(va_arg(*ap, int));
	else if (c == 'u')
		inf->str = NULL;/*ft_itoa_unsigned(va_arg(ap, int));*/
	else if (c == 'x')
		inf->str = ft_utoa_base(va_arg(*ap, int), X_MIN_BASE);
	else if (c == 'X' || c == 'p')
		inf->str = ft_utoa_base(va_arg(*ap, int), X_MAJ_BASE);
	else if (c == '%')
		inf->str = ft_strdup_char('%');
}

int			ft_flags(va_list *ap, char *str, infos *inf)
{
	int i;

	i = 0;
	if (str[i] == '*' || str[i] == '-' || ft_isdigit(str[i]))
		inf->spaces = ((str[i] == '*') ? va_arg(*ap, int) : ft_atoi_p(str));
	while (str[i] == '*' || str[i] == '-' || ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	if (str[i] == '*' || ft_isdigit(str[i]))
		inf->precision = ((str[i] == '*') ? va_arg(*ap, int) : ft_atoi_p(str));
	while (str[i] == '*' || ft_isdigit(str[i]))
		i++;
	if (ft_isconvert(str[i]))
		ft_convert(ap, str[i], inf);
	else
		i = -1;
	return (i + 1);
}

void		ft_init_infos(infos *inf)
{
	inf->str = NULL;
	inf->cv = 0;
	inf->precision = 0;
	inf->spaces = 0;
}

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
			format += ft_flags(&ap, (char *)format + 1, inf);
		if (inf->str)
		{
			new_s = ft_strjoin(new_s, inf->str);
			free(inf->str);
		}
		else
			new_s = ft_strjoin_char(new_s, *format);
		format++;
	}
	va_end(ap);
	ft_putstr_fd(new_s, 1);
	return (0);
}
