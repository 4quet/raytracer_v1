/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 14:59:09 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 12:27:11 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_vector	get_cylinder_normal(t_object *cylinder, t_vector e, t_vector d,
		double t)
{
	double		invr;
	t_vector	normal;

	invr = 1.0 / (cylinder->radius * cylinder->radius);
	normal = new_vector((e.x + d.x * t) * invr, 0, (e.z + d.z * t) * invr);
	normal = rotate(normal, cylinder->rotation);
	return (normalize(normal));
}

bool			intersect_cylinder(t_object *cylinder, t_ray *ray,
		t_info *inter_info)
{
	double		t;
	double		delta;
	t_vector	v;
	t_vector	e;
	t_vector	d;

	e = rotate(sub(ray->origin, cylinder->pos), inv(cylinder->rotation));
	d = rotate(ray->dir, inv(cylinder->rotation));
	v.x = (d.x * d.x) + (d.z * d.z);
	v.y = 2.0 * (e.x * d.x + e.z * d.z);
	v.z = (e.x * e.x) + (e.z * e.z) - (cylinder->radius * cylinder->radius);
	delta = (v.y * v.y) - (4.0 * v.x * v.z);
	if (delta < 0)
		return (false);
	t = positive_min(((-v.y) + sqrt(delta)) / (2.0 * v.x),
			((-v.y) - sqrt(delta)) / (2.0 * v.x));
	if (t < 0)
		return (false);
	inter_info->intersection = add(e, mult(d, t));
	inter_info->normal = get_cylinder_normal(cylinder, e, d, t);
	transform(cylinder, inter_info);
	return (true);
}
