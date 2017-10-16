/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 17:27:15 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:52:00 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_vector	new_vector(double const x, double const y, double const z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double		sqr(t_vector const vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

double		vector_len(t_vector const vector)
{
	return (sqrt(sqr(vector)));
}

t_vector	normalize(t_vector const vector)
{
	double	len;

	len = vector_len(vector);
	return (new_vector(vector.x / len, vector.y / len, vector.z / len));
}

t_vector	inv(t_vector const v)
{
	t_vector	r;

	r.x = -v.x;
	r.y = -v.y;
	r.z = -v.z;
	return (r);
}
