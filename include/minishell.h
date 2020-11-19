/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:54:19 by agossuin          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../tools/libft/include/libft.h"

# define MAX_ULONG "4294967295"
# define MAX_LLONG "9223372036854775807"
# define MAX_LLONG_NEG "9223372036854775808"
# define DIRECTORY_STATS 040000
# define OPERATORS "|;<>"
# define TRUE 1
# define FALSE 0
# define PROMPT "my_prompt$ "

enum			e_errors {
	MALLOC_ERROR = -11,
	WRITE_ERROR = -10,
	GNL_ERROR = -9,
	MUST_EXIT = -8,
	READING_ERROR = -7,
	INVALID_IDENTIFIER = 1,
	UNEXPECTED_EOF = 2,
	PERMISSION_DENIED = 3,
	HOME_NOT_SET = 4,
	NO_SUCH = 5,
	BAD_SUBSTITUTION = 10,
	IS_DIR = 126,
	COMMAND_NOT_FOUND = 127,
	PID_ERROR = 128,
	PIPE_ERROR = 129,
	SIGNAL_CTRL_C = 130,
	SIGNAL_CTRL_BS = 131,
	NUMERIC_ARGUMENT_REQUIRED = 255,
	AMBIGUOUS_REDIRECT = 257,
	SYNTAX_ERROR = 258,
};

enum			e_builtins {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

enum			e_end {
	SEMI = 0,
	PIPE = 1,
};

typedef struct	s_cmd
{
	t_list	*tokens;
	int		fd_in;
	int		fd_out;
	int		pipe_in;
	int		pipe_out;
	int		end;
}				t_cmd;

typedef struct	s_shell
{
	char		*line;
	t_list		*lexer;
	t_list		*pipeline;
}				t_sh;

/*
**  _           _ _ _   _
** | |__  _   _(_) | |_(_)_ __  ___
** | '_ \| | | | | | __| | '_ \/ __|
** | |_) | |_| | | | |_| | | | \__ \
** |_.__/ \__,_|_|_|\__|_|_| |_|___/
*/

void			ft_cd(t_list *tokens);

void			ft_echo(t_list *arg, int fd);

t_list			**ft_get_env();
void			ft_init_env(char **envp);
void			ft_putenv_fd(int fd);

void			ft_exec(t_cmd *cmd);
void			ft_pipeline(t_list *pipeline);

void			ft_exit(t_list *arg);

void			ft_export(t_list *args, int fd);

char			*ft_pwddup(void);
void			ft_set_oldpwd();
void			ft_set_pwd();
void			ft_pwd(int fd);

void			ft_unset_var(char *var);
void			ft_unset(t_list *args);

/*
**      _       _
**   __| | __ _| |_ __ _
**  / _` |/ _` | __/ _` |
** | (_| | (_| | || (_| |
**  \__,_|\__,_|\__\__,_|
*/

int				*ft_is_child_process();
void			ft_set_child_process(int pid);

void			ft_puterror(char *content, int error);
void			ft_puterror_syntax(char *content);
void			ft_puterror_ueof(char *content);

t_sh			**ft_get_msh();
void			ft_init_msh();
void			ft_delete_cmd(t_cmd *cmd);
void			ft_delete_pipeline(t_list **pipeline_ptr);
void			ft_delete_msh();

int				*ft_get_signal();
void			ft_set_signal(int new_signal);
void			signal_handler(int sig);

int				*ft_get_status();
int				*ft_get_last_status();
void			ft_set_status(int new_status);
void			ft_set_last_status();

/*
**   __                            _
**  / _| ___  _ __ _ __ ___   __ _| |_
** | |_ / _ \| '__| '_ ` _ \ / _` | __|
** |  _| (_) | |  | | | | | | (_| | |_
** |_|  \___/|_|  |_| |_| |_|\__,_|\__|
*/

void			ft_clean(t_list **token_ptr);

t_list			*get_next_pipeline(t_list **tokens_ptr);

void			get_redir(t_cmd *cmd);

int				ft_same_var(char *assignation, char *var);
char			*ft_vardup_from_env(char *str);
void			ft_assign_to_env(char *var);
char			*get_value(char **line_ptr);
int				ft_is_valid_var(char *str);

char			*ft_double_quote_dup(char **line_ptr);
char			*ft_single_quote_dup(char **line_ptr);
char			*ft_operator_dup(char **line_ptr);
char			*ft_simple_dup(char **line_ptr);
t_list			*ft_lexer(char *line);

void			ft_translate(t_list **token_ptr);

/*
**        _   _ _
**  _   _| |_(_) |___
** | | | | __| | / __|
** | |_| | |_| | \__ \
**  \__,_|\__|_|_|___/
*/

char			*fts_strjoin(char const *s1, char const *s2);
char			*fts_strdup(const char *s1);
void			*fts_calloc(size_t count, size_t size);
char			*fts_itoa(int nb);
t_list			*fts_lstnew(void *content);

int				ft_file_readable(char *path);
int				ft_file_permitted(char *path);
int				ft_file_directory(char *path);
int				ft_file_exists(char *path);
void			ft_close(int fd);

size_t			ft_lstlen(t_list *lst);
char			**ft_lsttotable(t_list *lst);
void			ft_free_table(char **table);
void			ft_lstput(t_list *lst);

int				ft_gt_max_llong(char *str, int is_neg);
int				ft_is_numeric(char *str);

char			*fts_strjoinfree(char *s1, char *s2);
char			*fts_chardup(char c);
int				ft_strcmp(char *s1, char *s2);
void			ft_lower_str(char *name);
int				ft_ispath(char *line);

void			fts_putstr_fd(char *s, int fd);
void			fts_putchar_fd(char c, int fd);
void			fts_putnbr_fd(int n, int fd);

/*
**  ___ _ __ ___
** / __| '__/ __|
** \__ \ | | (__
** |___/_|  \___|
*/

int				ft_id_builtin(char *name);
void			ft_builtin(t_cmd *cmd, int id);
void			ft_parser(t_cmd *cmd);

void			ft_system_pipe(t_list **lexer_ptr);
void			ft_system(void);

void			ft_last_command(t_cmd *cmd, int fd_in);
void			ft_parent_command(t_list *pipeline, int pipe_fd[2], pid_t pid);
void			ft_child_command(t_cmd *cmd, int pipe_fd[2], int fd_in);
void			ft_pipeline_recursion(t_list *pipeline, int fd_in);

void			ft_prompt();

#endif
