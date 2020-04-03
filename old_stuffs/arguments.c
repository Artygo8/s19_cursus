/*
 * CARE ABOUT check after if we have a space
 * Strong string dont interpret anything
 */

int		ms_stronglen(char *weak)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\'')
		i++;
	if (line[i] && line[i] == '\'' && ft_isspace(line[i + 1]))
		i++;
	return (i);
}

char	*ms_strongjoin(char *str, char *strong)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(ft_strlen(str) + ms_stronglen(strong) + 1);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (*strong && *strong != '\'')
		new[i++] = *strong++;
	if (*strong && *strong == '\'' && ft_isspace(*strong + 1))
		new[i++] = ' ';
	new[i] = '\0';
	return (new);
}

/*
 * Weak strings interpret $variables and \\, \", \`, \$
 */

int		ms_weaklen(char *weak)
{
	int count;
	int	i;

	if (!*weak)
		return(0);
	count = 1;
	i = 1;
	while (line[i] && (line[i] != '\"' || line[i - 1] == '\\'))
	{
		i++;
		if ()
	}
	return (i);
}

char	*ms_weakjoin(char *str, char *weak)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(ft_strlen(str) + ms_weaklen(weak) + 1);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (*weak && *weak != '\'')
		new[i++] = *weak++;
	new[i] = '\0';
	return (new);
}

char	*
