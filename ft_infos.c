/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:22 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:10:24 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_inf(t_inf *inf)
{
	inf->str = NULL;
	inf->cv = 0;
	inf->p = -1;
	inf->fw = 0;
	inf->zeros = 0;
}

int			ft_flag_inf(char *str, t_inf *inf)
{
	int		i;

	i = 0;
	while (ft_isflag(str[i]))
	{
		if (str[i] == '-')
			inf->fw = -1;
		if (str[i] == '0' && inf->fw != -1)
			inf->zeros = 1;
		if (inf->fw == -1)
			inf->zeros = 0;
		i++;
	}
	return (i);
}

int			ft_fw_inf(va_list *ap, char *str, t_inf *inf)
{
	int		i;

	i = 0;
	if (str[i] == '*' || ft_isdigit(str[i]))
	{
		if (inf->fw != -1)
			inf->fw = 1;
		inf->fw *= ((str[i] == '*') ? va_arg(*ap, unsigned int) : ft_atoi(str));
		inf->zeros *= inf->fw;
		i++;
	}
	while (ft_isdigit(str[i]) && str[0] != '*')
		i++;
	return (i);
}

int			ft_precision_inf(va_list *ap, char *str, t_inf *inf)
{
	int		i;

	i = 0;
	if (str[i] == '*' || ft_isdigit(str[i]))
		inf->p = ((str[i++] == '*') ? va_arg(*ap, unsigned int) : ft_atoi(str));
	while (ft_isdigit(str[i]) && str[0] != '*')
		i++;
	return (i);
}
