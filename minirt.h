/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:47:02 by agossuin          #+#    #+#             */
/*   Updated: 2019/11/28 16:48:40 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

/*
** Utils ***********************************************************************
*/

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

/*
** Mains ***********************************************************************
*/

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
}				t_data;

typedef struct	s_line
{
	t_vect	point;
	t_vect	dir;
}				t_line;

typedef struct	s_material
{
	t_vect	pos;
	t_vect	norm;
	double	dist;
	int		color;
	int		pxl;
}				t_mat;

/*
** Objects *********************************************************************
*/

typedef struct	s_camera
{
	int		id;
	t_vect	pos;
	t_vect	dir;
	t_vect	top;
	t_vect	right;
	int		dist;
	int		size_x;
	int		size_y;
}				t_cam; //attention, c'est idem que t_line

typedef struct	s_object
{
	int		id;
	t_vect	v1;
	t_vect 	v2;
	t_vect	v3;
	double	d1;
	double	d2;
	int		color;
	t_mat	(*fct)(struct s_object s, t_line l);
}				t_obj;

typedef struct	s_light
{
	int		type;
	t_vect	pos;
	double	percent;
	int		color;
}				t_light;


/*
**        ______                 __  _
**       / ____/_  ______  _____/ /_(_)___  ____  _____
**      / /_  / / / / __ \/ ___/ __/ / __ \/ __ \/ ___/
**     / __/ / /_/ / / / / /__/ /_/ / /_/ / / / (__  )
**    /_/    \__,_/_/ /_/\___/\__/_/\____/_/ /_/____/
*/


/*
** init.c
*/

int		ft_isspace(int c);
void	ft_objs_counter(char *line, t_rgb *count);
t_rgb	ft_objs_number(char *file);
void	ft_fill_objs(char *line, t_obj **objs, t_light **lights, t_cam **cams, t_rgb *id);
int		ft_init_rt(char *file, t_cam **cams, t_light **lights, t_obj **objs);
int		ft_next_arg(char *line);

/*
** tab.c
*/

void ft_place_objects(t_obj *objs, t_cam cam, t_mat **tab);
void	ft_obj_in_tab(t_obj s, t_cam cam, t_mat **tab);//, t_mat (*f)(t_obj, t_line));
t_mat	**ft_init_tab(t_cam cam, int color);
void	ft_put_tab(t_data data, t_mat **tab);

/*
**             __      _           __
**      ____  / /_    (_)__  _____/ /______
**     / __ \/ __ \  / / _ \/ ___/ __/ ___/
**    / /_/ / /_/ / / /  __/ /__/ /_(__  )
**    \____/_.___/_/ /\___/\___/\__/____/
**              /___/
*/

/*
** cam.c
*/

void	ft_init_cam(t_cam *cam, char *line);
void	ft_cam_res(t_cam *cam, char *line);

/*
** cylinder.c
*/

t_obj	ft_init_cyl(char *line, int id);
t_mat	ft_axis_cyl(t_obj cyl, t_line line);

/*
** light.c
*/

t_light	ft_init_light(char *line, int type);
t_mat ft_closest_obj(t_obj *objs, t_line ray);
void ft_put_lights(t_obj *objs, t_cam cam, t_light *lights, t_mat **tab);
void ft_put_light(t_obj *objs, t_cam cam, t_light light, t_mat **tab);
void ft_put_ambi(t_cam cam, t_light light, t_mat **tab);

/*
** plane.c
*/

t_obj	ft_init_plane(char *line, int id);
t_mat	ft_axis_plane(t_obj pl, t_line line);

/*
** sphere.c
*/

t_obj	ft_init_sphere(char *line, int id);
t_mat	ft_axis_sphere(t_obj s, t_line line);
//double	ft_closest(t_quad sol, t_line line);

/*
** square.c
*/

t_obj	ft_init_square(char *line, int id);
t_mat	ft_axis_square(t_obj sq, t_line line);

/*
** triangle.c
*/

t_obj	ft_init_tri(char *line, int id);
t_mat	ft_axis_tri(t_obj pl, t_line line);

/*
**             __  _ __
**      __  __/ /_(_) /____
**     / / / / __/ / / ___/
**    / /_/ / /_/ / (__  )
**    \__,_/\__/_/_/____/
*/

/*
** ato.c
*/

double ft_atof(char *s);
t_vect	ft_atovect(char *s);
t_rgb	ft_atorgb(char *s);

/*
** colors.c
*/

int		ft_rgb(int r, int g, int b);
int		ft_rgb_color(t_rgb rgb);
t_rgb	ft_color_rgb(int color);
t_rgb	ft_mult_rgb(t_rgb rgb, float m);
int		ft_mult_color(int color, float m);
t_rgb	ft_add_rgb(t_rgb rgb_1, t_rgb rgb_2);
int		ft_add_color(int color_1, int color_2);
t_rgb	ft_enlight_rgb(t_rgb rgb, t_rgb light);
int		ft_enlight_color(int color, int light);

/*
** equation.c
*/

double	ft_quad_solv(double a, double b, double c);

/*
** vect.c
*/

t_vect	ft_cross_prod(t_vect v1, t_vect v2);
double	ft_dot_prod(t_vect v1, t_vect v2);
double	ft_vect_len(t_vect v);
double	ft_vect_dist(t_vect v1, t_vect v2);
t_vect	ft_vect_add(t_vect v1, t_vect v2);
t_vect	ft_vect_sub(t_vect v1, t_vect v2);
t_vect	ft_vect_mult(t_vect v, double d);
t_vect	ft_vect_uni(t_vect v);

#endif
