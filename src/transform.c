/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 17:27:35 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:57:59 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_vector	rotate_x(t_vector const v, double const angle)
{
	double		c;
	double		s;
	t_vector	ret;

	c = cos((angle * M_PI) / 180.0);
	s = sin((angle * M_PI) / 180.0);
	ret.x = v.x;
	ret.y = v.y * c - v.z * s;
	ret.z = v.y * s + v.z * c;
	return (ret);
}

static t_vector	rotate_y(t_vector const v, double const angle)
{
	double		c;
	double		s;
	t_vector	ret;

	c = cos((angle * M_PI) / 180.0);
	s = sin((angle * M_PI) / 180.0);
	ret.x = v.x * c + v.z * s;
	ret.y = v.y;
	ret.z = v.x * (-s) + v.z * c;
	return (ret);
}

static t_vector	rotate_z(t_vector const v, double const angle)
{
	double		c;
	double		s;
	t_vector	ret;

	c = cos((angle * M_PI) / 180.0);
	s = sin((angle * M_PI) / 180.0);
	ret.x = v.x * c + v.y * (-s);
	ret.y = v.x * s + v.y * c;
	ret.z = v.z;
	return (ret);
}

t_vector		rotate(t_vector const v, t_vector const rotation)
{
	t_vector	n;

	n = rotate_x(v, rotation.x);
	n = rotate_y(n, rotation.y);
	n = rotate_z(n, rotation.z);
	return (n);
}

void			transform(t_object *object, t_info *info)
{
	info->intersection = rotate(info->intersection, object->rotation);
	info->intersection = add(info->intersection, object->pos);
	info->color = object->color;
	info->material = object->material;
}
