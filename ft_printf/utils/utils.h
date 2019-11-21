#ifndef UTILS_H
# define UTILS_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*ft_strdup_char(char c);
char	*ft_strjoin_char(char const *s1, char c);
int		int_size_base(long long n, int base_size);
char	*ft_utoa_base(unsigned int n, char *base);

#endif
