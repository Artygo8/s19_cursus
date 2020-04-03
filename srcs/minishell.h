#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"

enum			e_cmd
{
	ERROR = -1,		// error with the given command
	NOCMD,			// nothing given - only spaces
	MSH,			// "./executable" or msh "executable"
	ECHO,
	ECHON,			// with option -n
	CD,				// absolute or relative path
	PWD,			// like in bash
	EXPORT,			// like in bash
	UNSET,			// like in bash
	EXIT,			// like in bash
	ASSIGN,			// assign a variable to the environment, like x=1
	GET_ARG			// gets the value of an assigned variable
};

typedef struct	s_cmd
{
	char	*line;
	int		pos;
	int		cmd;
//	int		option;			// the only option is -n for the echo, so 1
	t_list	*args;
	t_list	*env;
	t_list	*vars;
	int		fd_output;
	int		fd_append;
	int		fd_input;
	int		exit_status;
}				t_cmd;

/*
 * ENV
 */

t_list	*ft_lstenv(char **envp);
void	ft_putenv(t_list *env);
int 	ft_var_to_env(t_list *env, const char *var);

/*
 * CMD
 */

void	put_cmd(t_cmd *cmd);
void	ft_reset_cmd(t_cmd *cmd);

/*
 * PROMPT
 */

int		ft_prompt(char *name, t_cmd *cmd);


#endif
