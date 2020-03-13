#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1000
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>

# include "../libs/ft_printf/ft_printf.h"

/*
** ft_prompt.c
*/

int		ft_prompt(char *name);

/*
** get_next_entry.c
*/

int		ft_putline(char const *s);
int		ft_strlen_endl(char const *s);
int		ft_strchr_pos(const char *s, int c);
char	*ft_strjoin_to_eol(char *s1, char *buf);
int		get_next_entry(char **line);

#endif
