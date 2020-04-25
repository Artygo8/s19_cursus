/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:35:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/25 18:41:48 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
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

int			get_next_line(char **line);
void		ft_bzero(void *b, size_t len);
int			ft_strlen_endl(char const *s);
int			ft_strchr_pos(const char *s, int c);
char		*ft_strjoin_to_eol(char *s1, char *buf);

/*
** rainbow.c
*/

float		cos_aprox(float rad);
float		sin_aprox(float rad);
size_t		ft_mult_color(size_t color, float m);
size_t		ft_rainbow(float ratio);

#endif
