/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:09:51 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/18 13:26:58 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			normalize_color(t_vector *c)
{
	if (c->x > 1)
		c->x = 1;
	if (c->y > 1)
		c->y = 1;
	if (c->z > 1)
		c->z = 1;
	if (c->x < 0)
		c->x = 0;
	if (c->y < 0)
		c->y = 0;
	if (c->z < 0)
		c->z = 0;
}

static t_vector	blend(t_vector const a, t_vector const b)
{
	t_vector	c;

	c.x = (a.x + b.x) / 2.0;
	c.y = (a.y + b.y) / 2.0;
	c.z = (a.z + b.z) / 2.0;
	return (c);
}

static t_vector	color_treatment(t_vector blended, double material_coeff)
{
	normalize_color(&blended);
	return (mult(blended, material_coeff));
}

t_vector		get_color(t_info info, t_light light, t_ray ray, bool blocked)
{
	t_vector	l;
	t_vector	c;
	double		d;

	l = (blocked == true) ? new_vector(0, 0, 0) : inv(light.ray.dir);
	c = new_vector(0, 0, 0);
	d = dot(info.normal, l);
	if (d > 0)
		c = add(c, color_treatment(blend(light.color, info.color),
					d * info.material.x));
	d = dot(normalize(ray.dir), sub(l, mult(info.normal, 2.0 * d)));
	if (d > 0)
		c = add(c, color_treatment(blend(light.color, info.color),
					pow(d, 50) * info.material.y));
	if (info.material.z > 0)
		c = add(c, mult(blend(light.color, info.color), info.material.z));
	c = mult(c, 1.0 / pow(info.light_obj_dist / 1.5, 2));
	normalize_color(&c);
	return (c);
}
