#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1000
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libs/ft_printf/ft_printf.h"

typedef struct	s_cmd	t_cmd;

enum			e_cmd
{
	ERROR = -1,		// error with the given command
	NOCMD,			// nothing given - only spaces
	MSH,			// "./executable" or msh "executable"
	ECHO,			// with option -n
	CD,				// absolute or relative path
	PWD,			// like in bash
	EXPORT,			// like in bash
	UNSET,			// like in bash
	EXIT,			// like in bash
	ASSIGN,			// assign a variable to the environment, like x=1
	GET_ARG		// gets the value of an assigned variable
};

enum			e_error
{
	MALLOC,
	CMD_NOT_FOUND
};

enum			e_redirect
{
	NONE,
	SAVE_OUT,
	APPEND_OUT,
	FILE_INPUT
};

struct	s_cmd
{
	int		cmd;
	int		option;			// the only option is -n for the echo, so 1
	int		exit_status;
	int		fd_output;
	int		fd_append;
	int		fd_input;
	t_list	*args;
	t_list	*env;
	t_list	*vars;
};

/*
** ft_prompt.c
*/

int		ms_prompt(char *name);

/*
** get_next_entry.c
*/

int		ft_putline(char const *s);
int		ft_strlen_endl(char const *s);
int		ft_strchr_pos(const char *s, int c);
char	*ft_strjoin_amount(char *s1, char *buf, int size);
char	*ft_strjoin_to_eol(char *s1, char *buf);
int		get_next_entry(char **line);

/*
** ms_get.c
*/

char	*ms_get_line_path(char *line);
int		ms_get_fd(t_cmd *cmd, char *line, int fd_type);
int		ms_get_cmd(t_cmd *cmd, char *line);
int		ms_get_arg(t_cmd *cmd, char *line);

void	ms_free_childs(t_cmd *cmd);
int		ms_reset_cmd(t_cmd *cmd);

#endif

// https://ryanstutorials.net/linuxtutorial/wildcards.php
// $? == retour de la dernière commande
