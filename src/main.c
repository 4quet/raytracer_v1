/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 13:45:43 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 14:00:16 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	main(int argc, char **argv)
{
	t_env	env;
	t_scene	scene;
	t_image	img;

	if (argc < 2)
	{
		ft_putendl_fd("rtv1: error: scene file missing", 2);
		return (-1);
	}
	read_scene_file(&scene, argv[1]);
	set_camera(&scene);
	scene.img = &img;
	env.scene = &scene;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, scene.name);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
