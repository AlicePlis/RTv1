/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:52 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:34:54 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define PLANE 4
# define POINT 1
# define DIR 50000
# define AMB 3
# define OFF 0
# define ON 1
# define WIDTH 1000
# define HEIGHT 800
# define RECUTSION 3
# define MIN 0
# define MAX 1

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_xyz
{
	double	x;
	double	y;
	double	z;
}				t_xyz;

typedef struct	s_light
{
	t_xyz	c;
	float	bright;
	int		type;
}				t_light;

typedef	struct	s_mouse
{
	int		x0;
	int		y0;
	float	x;
	float	y;
	float	button1;
	float	button2;
}				t_mouse;

typedef struct	s_obj
{
	int		type;
	int		r;
	t_xyz	c;
	t_xyz	axis;
	t_xyz	norm;
	t_color	color;
	double	k;
	double	reflect;
	double	transp;
	double	fi;
	double	tg;
	int		s;
	void	(*ft_obj_ray)(t_xyz, struct s_obj *, t_xyz, double[2]);
}				t_obj;

typedef	struct	s_param
{
	double	move_speed;
	double	zoom;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	int		move_x;
	int		move_y;
	int		move_z;
}				t_param;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_ptr;
	int		bpp;
	int		sl;
	int		end;
	int		width;
	int		height;
}				t_window;

typedef struct	s_str
{
	char	*str;
	int		x;
	int		y;
}				t_str;

typedef	struct	s_rays
{
	t_xyz		p;
	t_xyz		n;
	t_xyz		l;
	t_xyz		r;
	t_xyz		v;
	t_xyz		d;
	t_xyz		o;
}				t_rays;

typedef struct	s_rtv1
{
	int			obj_count;
	int			lt_count;
	t_window	*win;
	t_param		*prm;
	t_mouse		*mouse;
	t_obj		**obj;
	t_light		**light;
	t_xyz		o;
	int			y;
	int			y_end;
	int			ref;
	int			info;
}				t_rtv1;

t_rtv1			*init_struct(t_rtv1 *rtv, char *file);
void			start(t_rtv1 *rtv);
void			reset_param(t_rtv1 *rtv);
void			add_img(t_rtv1 *rtv, t_window *win);
void			info(t_rtv1 *rtv);

int				pars_stract(t_rtv1 *rtv, char *str);
t_obj			*pars_obj(char **split);
int				split_len(char **split);

void			draw(t_rtv1 *rtv);
t_color			raytrace(t_rtv1 *rtv, t_rays ray, double frames_t[2], int rec);
t_obj			*find_closest(t_rtv1 *rtv, double ft[2], t_rays r, double tn[2]);

double			light(t_rtv1 *rtv, t_rays ray, t_obj *obj);
t_rays			swap_ray(t_rays ray);
t_rays			add_rays(t_xyz d, t_obj *obj, t_xyz o, double t);

t_xyz			ft_newdot(double x, double y, double z);
t_light			*ft_newlight(t_xyz c, int type, float bright);
t_obj			*ft_newsphere(t_xyz c, int r, t_color color);
t_obj			*ft_newcylinder(t_xyz c, int r, t_color color, t_xyz axis);
t_obj			*ft_newcone(t_xyz c, t_color color, t_xyz axis, double fi);
t_obj			*ft_newplane(t_xyz c, t_color color, t_xyz axis);
t_color			ft_newcolor(int r, int g, int b);

double			ft_vdot(t_xyz a, t_xyz b);
t_xyz			ft_vsub(t_xyz a, t_xyz b);
double			ft_vlenght(t_xyz a);
t_xyz			ft_vmult(t_xyz a, double i);
t_xyz			ft_vadd(t_xyz a, t_xyz b);
t_xyz			ft_vnorm(t_xyz a);
t_xyz			ft_vcopy(t_xyz b);
t_xyz			ft_vreflect(t_xyz b, t_xyz	c);

void			ft_string_put(t_window *win, t_str str, int type);
t_str			ft_str(char *str, int x, int y);

void			ft_sphere(t_xyz ray, t_obj *obj, t_xyz oc, double t[2]);
void			ft_cylinder(t_xyz d, t_obj *obj, t_xyz oc, double t[2]);
void			ft_cone(t_xyz d, t_obj *obj, t_xyz oc, double t[2]);
void			ft_plane(t_xyz d, t_obj *obj, t_xyz oc, double t[2]);
t_xyz			ft_get_norm(t_xyz axis);

int				rgb_to_hex(t_color c);
t_color			rgb_color_mult(t_color c, double i);
t_color			color_add(t_color a, t_color b);

t_xyz			rotate(t_xyz dot, t_param *prm);
void			mouse_hook(t_rtv1 *rtv);
int				opt_key(int key, t_rtv1 *rtv);

#endif
