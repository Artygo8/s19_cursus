#include "libft.h"

void	ft_putword_fd(char *s, int fd)
{
	while (s && ft_isspace(*s))
		s++;
	while (s && *s && !ft_isspace(*s))
		write(fd, s++, 1);
}
