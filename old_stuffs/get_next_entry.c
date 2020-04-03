#include "minishell.h"

int		ft_putline(char const *s)
{
	return (write(1, s, ft_strlen_endl(s)));
}

int		ft_strlen_endl(char const *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

int		ft_strchr_pos(const char *s, int c)
{
	int pos;

	pos = 0;
	while (s && s[pos] && (s[pos] != c))
		pos++;
	if (s && s[pos] != c)
		pos = -1;
	return (pos);
}

char	*ft_strjoin_amount(char *s1, char *buf, int size)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = malloc(ft_strlen(s1) + size + 2))) //size ne tiens pas encore compte de l'exception des '\' (92)
		return (NULL);
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	j = (j > 0) ? j : 1;
	if (s1 && *buf != '\n' && s1[j - 1] != '\n')
		tab[i++] = ' ';
	j = 0;
	while (buf && buf[j] && buf[j] != 92 && j < size)
		tab[i++] = buf[j++];
	tab[i] = 0;
	free(s1);
	return (tab);
}

char	*ft_strjoin_to_eol(char *s1, char *buf)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = malloc(ft_strlen_endl(s1) + ft_strlen_endl(buf) + 1)))
		return (NULL);
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	while (buf && *buf && *buf != '\n')
		tab[i++] = *buf++;
	tab[i] = 0;
	free(s1);
	return (tab);
}

int		get_next_entry(char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	ret = 1;
	if (!(*line = ft_strjoin_to_eol(NULL, buf)))
		return (-1);
	while (ft_strchr_pos(buf, '\n') == -1 && ret && ret != -1)
	{
		ret = read(0, buf, BUFFER_SIZE);
		buf[ret] = 0;
		if (!(*line = ft_strjoin_to_eol(*line, buf)))
			return (-1);
	}
	if (buf[0] == 0)
		return (0);
	i = 0;
	ret = ft_strchr_pos(buf, '\n') + 1;
	while (buf[ret] != '\0' && ret)
		buf[i++] = buf[ret++];
	buf[i] = 0;
	return (1);
}
