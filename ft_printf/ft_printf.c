#include "ft_printf.h"

void		ft_convert(va_list *ap, char c, infos *inf)
{
	if (c == 'c')
		inf->str = ft_strdup_char(va_arg(*ap, int));
	else if (c == 's')
		inf->str = NULL;/*ft_strdup(va_arg(ap, char*));*/
	else if (c == 'p')
		inf->str = NULL;/*itoa_pointer(va_arg(ap, int));*/
	else if (c == 'd' || c == 'i')
		inf->str = NULL;/*ft_itoa(va_arg(ap, int));*/
	else if (c == 'u')
		inf->str = NULL;/*ft_itoa_unsigned(va_arg(ap, int));*/
	else if (c == 'x')
		inf->str = NULL;/*ft_itoa_base(va_arg(ap, int), X_MIN_BASE);*/
	else if (c == 'X')
		inf->str = NULL;/*ft_itoa_base(va_arg(ap, int), X_MAJ_BASE);*/
	else if (c == '%')
		inf->str = ft_strdup_char('%');
}

int			ft_flags(va_list *ap, char *str, infos *inf)
{
	static int i;

	i = 0;
	if (*str == '*' || *str == '-' || ft_isdigit(*str))
		inf->spaces = ((*str == '*') ? va_arg(*ap, int) : ft_atoi_p(str));
	while (*str == '*' || *str == '-' || ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	if (*str == '*' || ft_isdigit(*str))
		inf->precision = ((*str == '*') ? va_arg(*ap, int) : ft_atoi_p(str));
	while (*str == '*' || ft_isdigit(*str))
		str++;
	if (ft_isconvert(*str))
		ft_convert(ap, *str, inf);
	return (i);
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
	infos			inf;
	char			*new_s;

	new_s = NULL;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_infos(&inf);
			format += ft_flags(&ap, (char *)format, &inf);
		}
		if (inf.str)
			new_s = ft_strjoin(new_s, inf.str);
		else
			new_s = ft_strjoin_char(new_s, *format);
		format++;
	}
	va_end(ap);
	printf("%s\n", new_s);
	return (0);
}
