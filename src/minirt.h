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
# include "../includes/minilibx/mlx.h"
# include "../includes/libft/libft.h"
# define EPS 0.000001
# define PI 3.14159265
# define ALPHA 0xff000000
# define R 0xff0000
# define G 0x00ff00
# define B 0x0000ff
# define BACKGROUND 0
# define SPECULAR 64
# define SIZE_MAX_FLOAT 15

/*
** Utils ***********************************************************************
*/

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vect;

/*
** Mains ***********************************************************************
*/

typedef struct	s_line
{
	t_vect	ori;
	t_vect	dir;
}				t_line;

typedef struct	s_material
{
	int		id;
	int		x;
	int		y;
	t_vect	pos;
	t_vect	norm;
	double	dist;
	int		color;
	int		pxl;
}				t_mat;

typedef struct	s_data
{
	t_mat	**tab;
	void	*mlx_ptr;
	void	*mlx_win;
	int		res_x;
	int		res_y;
	t_list	*objs;
	t_list	*lights;
	t_list	*cams;
}				t_data;

/*
** Objects *********************************************************************
*/

typedef struct s_camera	t_cam;
typedef struct s_object	t_obj;
typedef struct s_light	t_light;

struct			s_camera
{
	int		id;
	t_vect	pos;
	t_vect	dir;
	t_vect	top;
	t_vect	right;
	int		dist;
	int		size_x;
	int		size_y;
};

struct			s_object
{
	int		id;
	t_vect	v1;
	t_vect	v2;
	t_vect	v3;
	double	d1;
	double	d2;
	int		color;
	t_mat	(*fct)(t_obj s, t_line l);
};

struct			s_light
{
	int		type;
	t_vect	pos;
	double	percent;
	int		color;
};

/*
**        ______                 __  _
**       / ____/_  ______  _____/ /_(_)___  ____  _____
**      / /_  / / / / __ \/ ___/ __/ / __ \/ __ \/ ___/
**     / __/ / /_/ / / / / /__/ /_/ / /_/ / / / (__  )
**    /_/    \__,_/_/ /_/\___/\__/_/\____/_/ /_/____/
*/


int	ft_bmp(t_data *data, char *file);


/*
** data.c
*/

t_mat			**ft_free_tab(t_mat **tab, int res_y);
void			ft_free_data(t_data *data, const char *str);
void			ft_show(t_data *data);
void			ft_obj_ids(t_list *objs);
t_data			*ft_data(char *file);

/*
** events.c
*/

int				ft_key(int key, void *p);
int				ft_mouse(int button, int x, int y, void *p);
int				ft_events(t_data *data);

/*
** materials.c
*/

t_vect			ft_screen(t_cam cam, int i, int j);
t_mat			ft_init_mat(t_vect pos);

/*
** parse.c
*/

t_list			*ft_lst_obj(char *line);
int				ft_init_rt(char *file, t_data *data);
int				ft_fill_objs(char *line, t_data *data);
int				ft_next_arg(char *line);

/*
** tab.c
*/

void			ft_place_objects(t_data *data, t_cam *cam, t_mat **tab);
void			ft_obj_in_tab(t_obj s, t_cam cam, t_mat **tab);
t_mat			**ft_init_tab(t_cam cam);
void			ft_put_tab(t_data data, t_mat **tab);

/*
**             __      _           __
**      ____  / /_    (_)__  _____/ /______
**     / __ \/ __ \  / / _ \/ ___/ __/ ___/
**    / /_/ / /_/ / / /  __/ /__/ /_(__  )
**    \____/_.___/_/ /\___/\___/\__/____/
**              /___/
*/

void	ft_specular(t_list *objs, t_cam *cam, t_light *light, t_mat **tab);

/*
** cam.c
*/

t_cam			*ft_init_cam(char *line);
void			ft_data_res(t_data *data, char *line);
void			ft_cam_ids(t_list *cam, int res_x, int res_y);

/*
** light.c
*/

t_light			*ft_init_light(char *line);
t_mat			ft_closest_obj(t_list *objs, t_line ray);
void			ft_put_lights(t_data *data, t_cam *cam, t_mat **tab);
void			ft_put_light(t_list *objs, t_cam *cam, t_light *l, t_mat **tab);
void			ft_put_ambi(t_cam *cam, t_light *light, t_mat **tab);

/*
** cylinder.c
*/

t_obj			*ft_init_cyl(char *line);
t_mat			ft_axis_cyl(t_obj cyl, t_line line);

/*
** plane.c
*/

t_obj			*ft_init_plane(char *line);
t_mat			ft_axis_plane(t_obj pl, t_line line);

/*
** sphere.c
*/

t_obj			*ft_init_sphere(char *line);
t_mat			ft_axis_sphere(t_obj s, t_line line);

/*
** square.c
*/

t_obj			*ft_init_square(char *line);
t_mat			ft_axis_square(t_obj sq, t_line line);

/*
** triangle.c
*/

t_obj			*ft_init_tri(char *line);
t_mat			ft_axis_tri(t_obj pl, t_line line);

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

double			ft_atof(char *s);
t_vect			ft_atovect(char *s);
int				ft_atocol(char *s);

/*
** colors.c
*/

int				ft_mult_color(int color, float m);
int				ft_add_color(int color_1, int color_2);
int				ft_enlight(int color, int light, double percent);

/*
** equation.c
*/

double			ft_quad_solv(double a, double b, double c);
double			ft_quad_solv2(double a, double b, double c);

/*
** istype.c
*/

int				ft_ischar(char *s);
int				ft_isrgb(char *s);
int				ft_len_float(char *s);
int				ft_isfloat(char *s);
int				ft_isvect(char *s);

/*
** vect.c
*/

t_vect			ft_cross(t_vect v1, t_vect v2);
double			ft_dot(t_vect v1, t_vect v2);
double			ft_v_len(t_vect v);
double			ft_v_dist(t_vect v1, t_vect v2);
t_vect			ft_v_add(t_vect v1, t_vect v2);
t_vect			ft_v_sub(t_vect v1, t_vect v2);
t_vect			ft_v_mult(t_vect v, double d);
t_vect			ft_v_uni(t_vect v);
t_vect			ft_v_dir(t_vect v1, t_vect v2);
t_line			ft_ray(t_vect origin, t_vect point);
t_vect			ft_refl(t_vect inc, t_vect norm);


#endif
