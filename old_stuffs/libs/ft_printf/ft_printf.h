/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:58 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/27 15:11:00 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define X_MAJ_BASE "0123456789ABCDEF"
# define X_MIN_BASE "0123456789abcdef"
# define BASE_TEN "0123456789"

typedef struct	s_informations
{
	char	*str;
	char	cv;
	int		p;
	int		fw;
	int		zeros;
}				t_inf;

/*
** ft_printf.c
*/

int				ft_printf(const char *s, ...);
int				ft_format(const char *s, va_list *ap, t_inf *inf);
int				ft_process(va_list *ap, char *s, t_inf *inf);
int				ft_pchar(va_list *ap, t_inf *inf);

/*
** ft_infos.c
*/

void			ft_init_inf(t_inf *inf);
int				ft_flag_inf(char *s, t_inf *inf);
int				ft_fw_inf(va_list *ap, char *s, t_inf *inf);
int				ft_precision_inf(va_list *ap, char *s, t_inf *inf);

/*
** ft_convert.c
*/

void			ft_convert(va_list *ap, char c, t_inf *inf);

/*
** ft_flags.c
*/

void			ft_flag_applier(t_inf *inf);
void			ft_special_cases(t_inf *inf);
void			ft_point_flag_str(t_inf *inf);
void			ft_point_flag_nbr(t_inf *inf);
void			ft_space_flags(t_inf *inf);

/*
** ft_istype.c
*/

int				ft_isinset(int n, char *s);
int				ft_isconvert(int n);
int				ft_isflag(int n);

#endif
