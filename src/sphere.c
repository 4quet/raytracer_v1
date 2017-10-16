/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:29:39 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 12:17:23 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

bool	intersect_sphere(t_object *sphere, t_ray *ray, t_info *inter_info)
{
	double		t;
	double		delta;
	t_vector	v;
	t_vector	e;

	e = add(ray->origin, inv(sphere->pos));
	v.x = sqr(ray->dir);
	v.y = 2 * ((e.x * ray->dir.x) + (e.y * ray->dir.y) + (e.z * ray->dir.z));
	v.z = sqr(e) - sphere->radius * sphere->radius;
	delta = (v.y * v.y) - (4.0 * v.x * v.z);
	if (delta < 0)
		return (false);
	t = positive_min(((-v.y) + sqrt(delta)) / (2.0 * v.x),
			((-v.y) - sqrt(delta)) / (2.0 * v.x));
	if (t < 0)
		return (false);
	inter_info->intersection = add(e, mult(ray->dir, t));
	inter_info->intersection = add(inter_info->intersection, sphere->pos);
	inter_info->normal = normalize(sub(inter_info->intersection, sphere->pos));
	inter_info->color = sphere->color;
	inter_info->material = sphere->material;
	return (true);
}
