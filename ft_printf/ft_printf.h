#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "utils/utils.h"

void		ft_convert(va_list *ap, char c, infos *inf);
char		*ft_flags(va_list *ap, char *str, infos *inf);
void		ft_init_infos(infos *inf);
int			ft_printf(const char *format, ...);

typedef struct informations
{
	char	*str;//to give
	char	cv;//converter on en a besoin
	int		precision;
	int		spaces;
}infos;

#endif
