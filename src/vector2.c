/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:49:02 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:50:29 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double		dot(t_vector const a, t_vector const b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	cross(t_vector const a, t_vector const b)
{
	t_vector	v;

	v.x = a.y * b.z - b.y * a.z;
	v.y = a.z * b.x - b.z * a.x;
	v.z = a.x * b.y - b.x * a.y;
	return (v);
}

t_vector	mult(t_vector const v, double const d)
{
	t_vector	ret;

	ret.x = v.x * d;
	ret.y = v.y * d;
	ret.z = v.z * d;
	return (ret);
}

t_vector	sub(t_vector const a, t_vector const b)
{
	t_vector	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vector	add(t_vector const a, t_vector const b)
{
	t_vector	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}
