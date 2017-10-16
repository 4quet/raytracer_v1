/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 14:42:01 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/20 12:41:53 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	set_inter(t_fp inter[4])
{
	inter[0] = intersect_sphere;
	inter[1] = intersect_plane;
	inter[2] = intersect_cylinder;
	inter[3] = intersect_cone;
}

static char	*read_parameter(int fd, char const *s)
{
	char	*line;

	if (get_next_line(fd, &line))
	{
		if (ft_strnequ(&line[1], s, ft_strlen(s)))
			return (line);
		free(line);
	}
	str_exit("error: scene description not well formated");
	return (NULL);
}

static void	get_scene_param(int fd, t_scene *scene)
{
	char	*line;

	if ((line = read_parameter(fd, "name")))
	{
		scene->name = get_line_str(line);
		free(line);
	}
	if ((line = read_parameter(fd, "camera")))
	{
		scene->cam.pos = get_line_vector(line);
		free(line);
	}
	if ((line = read_parameter(fd, "lookat")))
	{
		scene->cam.lookat = get_line_vector(line);
		free(line);
	}
	if ((line = read_parameter(fd, "upvec")))
	{
		scene->cam.upvec = get_line_vector(line);
		free(line);
	}
	set_inter(scene->inter);
}

int			is_object(char const *line)
{
	if (ft_strnequ(line, "sphere", 6))
		return (SPHERE);
	else if (ft_strnequ(line, "plane", 5))
		return (PLANE);
	else if (ft_strnequ(line, "cylinder", 8))
		return (CYLINDER);
	else if (ft_strnequ(line, "cone", 4))
		return (CONE);
	else if (ft_strnequ(line, "light", 5))
		return (LIGHT);
	return (0);
}

void		read_scene_file(t_scene *scene, char const *path)
{
	int		fd;
	char	*line;
	int		o;
	int		l;
	int		type;

	if ((fd = open(path, O_RDONLY | O_NOFOLLOW)) == FAIL || isdir(path))
		str_exit("read_scene_file(): error: open() failed");
	get_amounts(scene, fd);
	close(fd);
	if ((fd = open(path, O_RDONLY)) == FAIL)
		str_exit("read_scene_file(): error: open() failed");
	o = 0;
	l = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strnequ(line, "scene", 5))
			get_scene_param(fd, scene);
		type = is_object(line);
		if (type == LIGHT)
			get_light(fd, scene, &l);
		else if (type >= 1 && type <= 4)
			get_object(fd, scene, &o, type);
		free(line);
	}
}
