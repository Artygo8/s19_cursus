/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:47 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:09:49 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_convert(va_list *ap, char c, t_inf *inf)
{
	inf->cv = c;
	if (c == 'c')
		return ;
	else if (c == 's')
		inf->str = ft_strdup(va_arg(*ap, char*));
	else if (c == 'd' || c == 'i')
		inf->str = ft_itoa(va_arg(*ap, int));
	else if (c == 'u')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned int), BASE_TEN);
	else if (c == 'x')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned int), X_MIN_BASE);
	else if (c == 'X')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned int), X_MAJ_BASE);
	else if (c == '%')
		inf->str = ft_strdup("%");
	else if (c == 'p')
		inf->str = ft_utoa_base(va_arg(*ap, unsigned long), X_MIN_BASE);
	ft_flag_applier(inf);
}
