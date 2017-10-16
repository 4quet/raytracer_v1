/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:36:14 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/18 15:06:29 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	is_closer(t_info *closest_info,
		t_info inter_info,
		t_vector ray_origin,
		size_t index)
{
	double	tmp;

	tmp = sqr(sub(inter_info.intersection, ray_origin));
	if (tmp < closest_info->distance)
	{
		*closest_info = inter_info;
		closest_info->distance = tmp;
		closest_info->index = index;
	}
}

void		raytrace(t_scene *s, t_ray ray, int x, int y)
{
	size_t	i;
	t_info	inter_info;
	t_info	closest_info;

	i = 0;
	closest_info.distance = DBL_MAX;
	closest_info.index = -1;
	while (i < s->objects_n)
	{
		if ((*s->inter[s->objects[i].type - 1])(&s->objects[i], &ray,
					&inter_info))
			is_closer(&closest_info, inter_info, ray.origin, i);
		i++;
	}
	if (closest_info.index != -1)
		put_pixel(s->img, x, y, get_shadow(s, closest_info, ray));
}
