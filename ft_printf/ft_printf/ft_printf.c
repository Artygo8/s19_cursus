/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:53 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:10:54 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_inf			*inf;
	unsigned int	size;

	if (!format)
		return (0);
	if (!(inf = (t_inf*)(malloc(sizeof(t_inf)))))
		return (0);
	va_start(ap, format);
	size = ft_format(format, &ap, inf);
	va_end(ap);
	free(inf);
	return (size);
}

int			ft_format(const char *format, va_list *ap, t_inf *inf)
{
	int		size;

	size = 0;
	while (*format)
	{
		ft_init_inf(inf);
		if (*format == '%')
		{
			format += ft_process(ap, (char *)format + 1, inf);
			size += (inf->cv == 'c') ? ft_pchar(ap, inf) : ft_strlen(inf->str);
			if (inf->str)
				ft_putstr_fd(inf->str, 1);
		}
		if (!inf->str && (inf->cv != 'c' || inf->cv == 0))
		{
			write(1, format, 1);
			size++;
		}
		else if (!inf->str && inf->cv != 0 && inf->cv != 'c')
			break ;
		free(inf->str);
		format++;
	}
	return (size);
}

int			ft_process(va_list *ap, char *str, t_inf *inf)
{
	int i;

	i = 0;
	i += ft_flag_inf(&str[i], inf);
	i += ft_fw_inf(ap, &str[i], inf);
	if (str[i] == '.')
	{
		inf->p = 0;
		i++;
		i += ft_precision_inf(ap, &str[i], inf);
	}
	if (ft_isconvert(str[i]))
		ft_convert(ap, str[i], inf);
	return ((ft_isconvert(str[i])) ? i + 1 : 0);
}

int			ft_pchar(va_list *ap, t_inf *inf)
{
	int i;

	i = 1;
	while (inf->fw > 1)
	{
		write(1, " ", 1);
		inf->fw--;
		i++;
	}
	ft_putchar_fd(va_arg(*ap, int), 1);
	while (inf->fw < -1)
	{
		write(1, " ", 1);
		inf->fw++;
		i++;
	}
	return (i);
}
