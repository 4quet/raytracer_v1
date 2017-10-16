/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:12:47 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/20 12:40:20 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# include <stdbool.h>
# include <float.h>
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>

# define WINDOW_WIDTH	1680
# define WINDOW_HEIGHT	1050
# define ESC			53
# define SPHERE			1
# define PLANE			2
# define CYLINDER		3
# define CONE			4
# define LIGHT			5
# define FAIL			-1

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
}				t_ray;

typedef	struct	s_info
{
	int			index;
	double		distance;
	double		light_obj_dist;
	double		light_inter_dist;
	t_vector	intersection;
	t_vector	normal;
	t_vector	color;
	t_vector	material;
}				t_info;

typedef struct	s_light
{
	t_ray		ray;
	t_vector	color;
}				t_light;

typedef struct	s_object
{
	int			type;
	double		radius;
	t_vector	pos;
	t_vector	normal;
	t_vector	rotation;
	t_vector	color;
	t_vector	material;
}				t_object;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	lookat;
	t_vector	upvec;
	t_vector	dir_vector;
	t_vector	right_vector;
	t_vector	up_vector;
}				t_camera;

typedef struct	s_image
{
	void		*id;
	int			*data;
	int			bpp;
	int			line;
	int			endian;
}				t_image;

/*
** COLOR.C **
*/
void			normalize_color(t_vector *c);
t_vector		get_color(t_info info, t_light light, t_ray ray, bool blocked);

typedef bool	(*t_fp)(t_object*, t_ray*, t_info*);

typedef struct	s_scene
{
	char		*name;
	size_t		objects_n;
	size_t		lights_n;
	t_fp		inter[4];
	t_camera	cam;
	t_image		*img;
	t_vector	viewplan;
	t_vector	vp_upleft;
	t_object	*objects;
	t_light		*lights;
}				t_scene;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
}				t_env;

/*
** HOOK.C **
*/
int				key_hook(int keycode, t_env *env);
int				expose_hook(t_env *env);

/*
** SCENE_FILE.C **
*/
void			read_scene_file(t_scene *scene, char const *path);
int				is_object(char const *line);

/*
** LINE_VALUE.C **
*/
double			get_line_double(char const *line);
char			*get_line_str(char const *line);
t_vector		get_line_vector(char const *line);

/*
** OBJ_VALUE.C **
*/
void			get_light(int fd, t_scene *scene, int *index);
void			get_object(int fd, t_scene *scene, int *index, int type);
void			get_amounts(t_scene *s, int const fd);

/*
** CAMERA.C **
*/
void			set_camera(t_scene *scene);
t_vector		get_directional_vector(t_scene *scene, int x, int y);

/*
** DRAW.C **
*/
void			draw(t_scene *scene);

/*
** RAYTRACE.C **
*/
void			raytrace(t_scene *scene, t_ray ray, int x, int y);

/*
** UTILS.C **
*/
void			put_pixel(t_image *img, int x, int y, t_vector color);
double			positive_min(double a, double b);
bool			isdir(char const *path);
void			str_exit(char const *str);

/*
** VECTOR.C **
*/
t_vector		new_vector(double const x, double const y, double const z);
double			sqr(t_vector const vector);
double			vector_len(t_vector const vector);
t_vector		normalize(t_vector const vector);
t_vector		inv(t_vector const v);

/*
** VECTOR2.C **
*/
t_vector		add(t_vector const a, t_vector const b);
t_vector		sub(t_vector const a, t_vector const b);
double			dot(t_vector const a, t_vector const b);
t_vector		cross(t_vector const a, t_vector const b);
t_vector		mult(t_vector const v, double const d);

/*
** GET_SHADOW.C **
*/
t_vector		get_shadow(t_scene *s, t_info closest_info, t_ray ray);

/*
** SPHERE.C **
*/
bool			intersect_sphere(t_object *s, t_ray *ray, t_info *inter_info);

/*
** PLANE.C **
*/
bool			intersect_plane(t_object *p, t_ray *ray, t_info *inter_info);

/*
** CYLINDER.C **
*/
bool			intersect_cylinder(t_object *c, t_ray *ray, t_info *inter_info);

/*
** CONE.C **
*/
bool			intersect_cone(t_object *co, t_ray *ray, t_info *inter_info);

/*
** TRANSFORM.C **
*/
t_vector		rotate(t_vector const v, t_vector const rotation);
void			transform(t_object *object, t_info *info);

#endif
