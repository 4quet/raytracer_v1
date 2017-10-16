/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:10:03 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:18:14 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_vector	get_cone_normal(t_object *cone, t_vector intersection)
{
	t_vector normal;

	normal.x = intersection.x;
	normal.z = intersection.z;
	normal.y = -0.1 * intersection.y;
	normal = rotate(normal, cone->rotation);
	return (normalize(normal));
}

bool			intersect_cone(t_object *cone, t_ray *ray, t_info *inter_info)
{
	double		t;
	double		delta;
	t_vector	e;
	t_vector	d;
	t_vector	v;

	e = rotate(sub(ray->origin, cone->pos), inv(cone->rotation));
	d = rotate(ray->dir, inv(cone->rotation));
	v.x = (d.x * d.x) + (d.z * d.z) - (d.y * d.y * cone->radius);
	v.y = 2 * ((e.x * d.x) + (e.z * d.z)) - 2 * (e.y * d.y * cone->radius);
	v.z = (e.x * e.x) + (e.z * e.z) - (e.y * e.y) * cone->radius;
	delta = (v.y * v.y) - (4.0 * v.x * v.z);
	if (delta < 0)
		return (false);
	t = positive_min(((-v.y) + sqrt(delta)) / (2.0 * v.x),
			((-v.y) - sqrt(delta)) / (2.0 * v.x));
	if (t < 0)
		return (false);
	inter_info->intersection = add(e, mult(d, t));
	inter_info->normal = get_cone_normal(cone, inter_info->intersection);
	transform(cone, inter_info);
	return (true);
}
