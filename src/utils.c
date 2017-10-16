/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 17:27:30 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/20 12:39:12 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	put_pixel(t_image *img, int x, int y, t_vector c)
{
	int	i;
	int	clr;

	clr = (int)(c.x * 255) * 65536 + (int)(c.y * 255) * 256 + (int)(c.z * 255);
	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		i = ((img->line / 4) * y) + (x);
		if (img)
			img->data[i] = clr;
	}
}

bool	isdir(char const *path)
{
	struct stat info;

	lstat(path, &info);
	if (S_ISDIR(info.st_mode))
		return (true);
	return (false);
}

double	positive_min(double a, double b)
{
	if (a < 0 && b < 0)
		return (-1);
	if (a < 0)
		return (b);
	if (b < 0)
		return (a);
	return (a < b) ? a : b;
}

void	str_exit(char const *str)
{
	ft_putendl_fd(str, 2);
	exit(FAIL);
}
