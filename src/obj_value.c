/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:32:18 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/20 12:36:59 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	set_default(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < scene->objects_n)
	{
		scene->objects[i].pos = new_vector(0, 0, 0);
		scene->objects[i].rotation = new_vector(0, 0, 0);
		scene->objects[i].color = new_vector(1, 1, 1);
		scene->objects[i].material = new_vector(0.5, 0.5, 0.2);
		scene->objects[i].radius = 1;
		i++;
	}
	i = 0;
	while (i < scene->lights_n)
	{
		scene->lights[i].ray.origin = new_vector(0, 0, 0);
		scene->lights[i].color = new_vector(1, 1, 1);
		i++;
	}
}

void		get_amounts(t_scene *s, int const fd)
{
	char	*line;
	int		type;

	s->objects_n = 0;
	s->lights_n = 0;
	while (get_next_line(fd, &line))
	{
		type = is_object(line);
		if (type == LIGHT)
			s->lights_n += 1;
		else if (type >= 1 && type <= 4)
			s->objects_n += 1;
		free(line);
	}
	if (s->objects_n == 0 || s->lights_n == 0)
		str_exit("error: scene must have at least one light and one object");
	if (!(s->lights = (t_light *)malloc(sizeof(t_light) * s->lights_n)))
		str_exit("get_amounts(): error: malloc() failed");
	if (!(s->objects = (t_object *)malloc(sizeof(t_object) * s->objects_n)))
		str_exit("get_amounts(): error: malloc() failed");
	set_default(s);
}

void		get_object(int fd, t_scene *scene, int *index, int type)
{
	char		*line;
	int			ret;

	line = NULL;
	while (!ft_strequ(line, "end"))
	{
		ret = get_next_line(fd, &line);
		if (!ret || !line[0])
			str_exit("error: object description not well formated");
		else if (ft_strnequ(&line[1], "translate", 9))
			scene->objects[*index].pos = get_line_vector(line);
		else if (ft_strnequ(&line[1], "rotate", 6))
			scene->objects[*index].rotation = get_line_vector(line);
		else if (ft_strnequ(&line[1], "color", 5))
			scene->objects[*index].color = get_line_vector(line);
		else if (ft_strnequ(&line[1], "material", 8))
			scene->objects[*index].material = get_line_vector(line);
		else if (ft_strnequ(&line[1], "normal", 6))
			scene->objects[*index].normal = get_line_vector(line);
		else if (ft_strnequ(&line[1], "radius", 6))
			scene->objects[*index].radius = get_line_double(line);
		free(line);
	}
	scene->objects[*index].type = type;
	*index += 1;
}

void		get_light(int fd, t_scene *scene, int *index)
{
	char	*line;
	int		ret;

	line = NULL;
	while (!ft_strequ(line, "end"))
	{
		ret = get_next_line(fd, &line);
		if (!ret || !line[0])
			str_exit("error: light description not well formated");
		else if (ft_strnequ(&line[1], "translate", 9))
			scene->lights[*index].ray.origin = get_line_vector(line);
		else if (ft_strnequ(&line[1], "color", 5))
			scene->lights[*index].color = get_line_vector(line);
		free(line);
	}
	*index += 1;
}
