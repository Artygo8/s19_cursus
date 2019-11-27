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
	char			*new_s;
	unsigned int	size;

	va_start(ap, format);
	if (!(inf = (t_inf*)malloc(sizeof(t_inf))))
		return (0);
	new_s = ft_format(format, &ap, inf);
	ft_putstr_fd(new_s, 1);
	size = ft_strlen(new_s);
	va_end(ap);
	free(new_s);
	return (0);
}

char		*ft_format(const char *format, va_list *ap, t_inf *inf)
{
	char	*new_s;
	char	*tmp;

	new_s = NULL;
	while (*format)
	{
		ft_init_inf(inf);
		if (*format == '%')
		{
			format += ft_process(ap, (char *)format + 1, inf);
			if (inf->str)
				tmp = ft_strjoin(new_s, inf->str);
		}
		if (!inf->str)
			tmp = ft_strjoin_char(new_s, *format);
		free(inf->str);
		free(new_s);
		new_s = tmp;
		format++;
	}
	return (new_s);
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
	}
	i += ft_precision_inf(ap, &str[i], inf);
	if (ft_isconvert(str[i]))
		ft_convert(ap, str[i], inf);
	return ((ft_isconvert(str[i])) ? i + 1 : 0);
}
