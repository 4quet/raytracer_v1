/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:21:15 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/18 15:06:00 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

bool	intersect_plane(t_object *plane, t_ray *ray, t_info *inter_info)
{
	double		t;
	double		dv;
	t_vector	e;
	t_vector	d;

	e = rotate(ray->origin, inv(plane->rotation));
	d = rotate(ray->dir, inv(plane->rotation));
	dv = dot(plane->normal, d);
	if (dv == 0)
		return (false);
	t = (-dot(plane->normal, sub(e, plane->pos))) / dv;
	if (t < 0)
		return (false);
	inter_info->intersection = add(e, mult(d, t));
	inter_info->normal = (dv < 0) ? plane->normal : inv(plane->normal);
	inter_info->normal = normalize(rotate(inter_info->normal, plane->rotation));
	inter_info->intersection = rotate(inter_info->intersection,
			plane->rotation);
	inter_info->color = plane->color;
	inter_info->material = plane->material;
	return (true);
}
