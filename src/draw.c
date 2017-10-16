/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:00:03 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 14:23:45 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	draw(t_scene *scene)
{
	t_ray	ray;
	int		x;
	int		y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ray.origin = scene->cam.pos;
			ray.dir = normalize(get_directional_vector(scene, x, y));
			raytrace(scene, ray, x, y);
			x++;
		}
		y++;
	}
}
