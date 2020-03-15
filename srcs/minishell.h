#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1000
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libs/ft_printf/ft_printf.h"

enum			e_cmd
{
	ERROR = -1;		// error with the given command
	NONE;			// nothing given - only spaces
	MSH;			// "./executable" or msh "executable"
	ECHO;			// with option -n
	CD;				// absolute or relative path
	PWD;			// like in bash
	EXPORT;			// like in bash
	UNSET;			// like in bash
	EXIT;			// like in bash
	ASSIGN;			// assign a variable to the environment, like x=1
	GET_ARG;		// gets the value of an assigned variable
};

enum			e_redirect
{
	NONE;
	SAVE_OUT;
	APPEND_OUT;
	PIPE;
	FILE_INPUT;
};

typedef struct	s_cmd
{
	int		cmd;
	int		last_return;
	int		option;			//the only option is -n for the echo
	char	*arg;
	int		redirect;
}				t_cmd;

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
char	*ft_strjoin_buf(char *s1, char *buf);
char	*ft_strjoin_to_eol(char *s1, char *buf);
int		get_next_entry(char **line);



#endif

// https://ryanstutorials.net/linuxtutorial/wildcards.php
// $? == retour de la dernière commande
