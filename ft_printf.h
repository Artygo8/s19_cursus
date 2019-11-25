#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define X_MAJ_BASE "0123456789ABCDEF"
# define X_MIN_BASE "0123456789abcdef"
# define BASE_TEN "0123456789"

typedef struct s_informations
{
	char	*str;	//to give
	char	cv;		//converter on en a besoin
	int		p;
	int		fw;
	int		zeros;
}t_inf;

/*
 * ft_printf.c
 */

int			ft_printf(const char *format, ...);
char		*ft_format(const char *format, va_list *ap, t_inf *inf);
int			ft_process(va_list *ap, char *str, t_inf *inf);

/*
 * ft_infos.c
 */

void		ft_init_inf(t_inf *inf);
int			ft_flag_inf(char *str, t_inf *inf);
int			ft_fw_inf(va_list *ap, char *str, t_inf *inf);
int			ft_precision_inf(va_list *ap, char *str, t_inf *inf);

/*
 * ft_convert.c
 */

void		ft_convert(va_list *ap, char c, t_inf *inf);

/*
 * ft_flags.c
 */

void		ft_flag_applier(t_inf *inf);
void 		ft_special_cases(t_inf *inf);
void		ft_point_flag_str(t_inf *inf);
void		ft_point_flag_nbr(t_inf *inf);
void		ft_space_flags(t_inf *inf);

/*
 * ft_istype.c
 */

int			ft_isinset(int c, char *str);
int			ft_isconvert(int c);
int			ft_isflag(int c);

/*
 * ft_utils_str.c
 */

char		*ft_strdup_char(char c);
char		*ft_strjoin_char(char const *s1, char c);

#endif
