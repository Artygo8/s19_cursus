/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/26 21:17:33 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define PI 3.14159265
# define R 0xff0000
# define G 0x00ff00
# define B 0x0000ff
# define ERROR "\e[31;2mInvalid argument\e[m"
# define USAGE "./color [0-255 0-255 0-255] [[-r] [0.0 - 255.0]] [[-rr] \
[0.0 - 255.0]] [-underlined] [-bold] [-random]"

typedef struct	s_cmd
{
	float	rb;
	float	revrb;
	int		random;
	int		start;
	float	start_ratio;
	int		revstart;
	int		bold;
	int		underlined;
	int		color;
	int		color_bg;
}				t_cmd;

/*
** color.c
*/

void		print_char(char c, t_cmd *cmd);
void		ft_print_double_rainbow(char *line, t_cmd *cmd);
void		ft_print_reverse_rainbow(char *line, t_cmd *cmd);
void		ft_print_rainbow(char *line, t_cmd *cmd);
void		ft_print_random_colors(char *line, t_cmd *cmd);


/*
** get_next_line_exam.c
*/

int			ft_strlen_endl(char const *s);
int			ft_strchr_pos(const char *s, int c);
char		*ft_strjoin_to_eol(char *s1, char *buf);
int			get_next_line(char **line);

/*
** main.c
*/

void		ft_printer(char *line, t_cmd *cmd);
void		ft_colorize(t_cmd *cmd);

/*
** math.c
*/

int			fact(int n);
float		sin_aprox(float rad);
float		cos_aprox(float rad);

/*
** parsing.c
*/

int			ft_isfloat(const char *str);
int			ft_iscolor(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_parsing(int argc, char const *argv[], t_cmd *cmd);

/*
** rainbow.c
*/

size_t		ft_add_color(size_t color_1, size_t color_2);
size_t		ft_mult_color(size_t color, float m);
int			rot_color(int start, int index);
size_t		ft_rainbow(float ratio, int s);


#endif
