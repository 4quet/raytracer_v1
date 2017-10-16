/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:36:39 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:16:44 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		set_camera(t_scene *s)
{
	t_vector	rv;
	t_vector	uv;
	t_vector	dv;

	s->viewplan.x = 1.6;
	s->viewplan.y = 0.9;
	s->viewplan.z = 3.0;
	s->cam.dir_vector = normalize(sub(s->cam.lookat, s->cam.pos));
	s->cam.right_vector = cross(s->cam.upvec, s->cam.dir_vector);
	s->cam.up_vector = cross(s->cam.dir_vector, s->cam.right_vector);
	rv = mult(s->cam.right_vector, s->viewplan.x / 2.0);
	uv = mult(s->cam.up_vector, s->viewplan.y / 2.0);
	dv = mult(s->cam.dir_vector, s->viewplan.z);
	s->vp_upleft = add(s->cam.pos, sub(add(dv, uv), rv));
}

t_vector	get_directional_vector(t_scene *scene, int x, int y)
{
	double		x_indent;
	double		y_indent;
	t_vector	tmp;

	x_indent = scene->viewplan.x / (double)WINDOW_WIDTH;
	y_indent = scene->viewplan.y / (double)WINDOW_HEIGHT;
	tmp = add(scene->vp_upleft,
			sub(mult(scene->cam.right_vector, x_indent * x),
				mult(scene->cam.up_vector, y_indent * y)));
	return (sub(tmp, scene->cam.pos));
}
