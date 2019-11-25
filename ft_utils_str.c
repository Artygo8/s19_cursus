#include "ft_printf.h"

char	*ft_strdup_char(char c)
{
	char	*new_s;
	int		i;

	i = 0;
	if (!(new_s = malloc((c != 0) + 1 * sizeof(char))))
		return (NULL);
	if (c)
		new_s[i++] = (unsigned char)c;
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc((ft_strlen(s1) + (c != 0) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && *s1)
		new[i++] = *s1++;
	if (c)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}
