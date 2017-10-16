/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 14:40:11 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/18 16:20:46 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	expose_hook(t_env *env)
{
	static bool drawed = false;

	if (!drawed)
	{
		env->scene->img->id = mlx_new_image(env->mlx,
				WINDOW_WIDTH, WINDOW_HEIGHT);
		env->scene->img->data = (int *)mlx_get_data_addr(env->scene->img->id,
				&env->scene->img->bpp,
				&env->scene->img->line,
				&env->scene->img->endian);
		draw(env->scene);
		mlx_put_image_to_window(env->mlx, env->win, env->scene->img->id, 0, 0);
		drawed = true;
	}
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == ESC)
	{
		ft_putendl("RTV1: escape pressed");
		exit(0);
	}
	return (0);
}
