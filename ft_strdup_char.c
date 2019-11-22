#include "ft_printf.h"

char	*ft_strdup_char(char c)
{
	char	*new_s;
	int		i;

	i = 0;
	if (!(new_s = malloc((c != 0) + 1 * sizeof(char))))
		return (NULL);
	if (c)
		new_s[i++] = c;
	new_s[i] = '\0';
	return (new_s);
}
