#include "ft_printf.h"

void		ft_convert(va_list *ap, char c, t_inf *inf)
{
	inf->cv = c;
	if (c == 'c')
		inf->str = ft_strdup_char(va_arg(*ap, int));
	else if (c == 's')
		inf->str = ft_strdup(va_arg(*ap, char*));
	if (c == 'd' || c == 'i')
		inf->str = ft_itoa(va_arg(*ap, int));
	else if (c == 'u')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned long), BASE_TEN);
	else if (c == 'x')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned long), X_MIN_BASE);
	else if (c == 'X')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned long), X_MAJ_BASE);
	else if (c == '%')
		inf->str = ft_strdup_char('%');
	else if (c == 'p')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned long), X_MIN_BASE);
	ft_flag_applier(inf);
}
