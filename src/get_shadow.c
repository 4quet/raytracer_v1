/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:01:15 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/18 15:03:09 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static bool	is_blocked(t_info *closest_info, t_vector dist)
{
	closest_info->light_inter_dist = vector_len(dist);
	if (closest_info->light_inter_dist < closest_info->light_obj_dist)
	{
		return (true);
	}
	return (false);
}

static void	set_light_dir(t_ray *ray, t_info *closest_info)
{
	ray->dir = sub(closest_info->intersection, ray->origin);
	closest_info->light_obj_dist = vector_len(ray->dir);
	ray->dir = normalize(ray->dir);
}

static bool	intersect_type(t_scene *s, t_info *closest_info, size_t i, size_t j)
{
	t_info		inter_info;

	if ((*s->inter[s->objects[j].type - 1])(&s->objects[j], &s->lights[i].ray,
				&inter_info))
		return (is_blocked(closest_info, sub(inter_info.intersection,
						s->lights[i].ray.origin)));
	else
		return (false);
}

t_vector	get_shadow(t_scene *s, t_info closest_info, t_ray ray)
{
	size_t		i;
	size_t		j;
	bool		blocked;
	t_vector	color;

	i = 0;
	color = new_vector(0, 0, 0);
	while (i < s->lights_n)
	{
		j = 0;
		blocked = false;
		set_light_dir(&s->lights[i].ray, &closest_info);
		while (j < s->objects_n)
		{
			if ((int)j != closest_info.index)
				if (intersect_type(s, &closest_info, i, j))
					blocked = true;
			j++;
		}
		color = add(color, get_color(closest_info, s->lights[i], ray, blocked));
		i++;
	}
	normalize_color(&color);
	return (color);
}
