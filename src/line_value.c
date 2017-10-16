/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:24:08 by lfourque          #+#    #+#             */
/*   Updated: 2015/12/17 13:44:28 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

char		*get_line_str(char const *line)
{
	int	i;
	int	begin;
	int	len;

	i = 0;
	while (line[i])
	{
		if (line[i] == '{')
		{
			begin = i + 1;
			while (line[i] != '}')
				i++;
			len = i - begin;
		}
		i++;
	}
	return (ft_strsub(line, begin, len));
}

t_vector	get_line_vector(char const *line)
{
	int			i;
	bool		done;
	t_vector	coord;

	done = false;
	i = 0;
	while (!done && line[i])
	{
		if (line[i] == '{')
		{
			coord.x = atof(&line[i + 1]);
			while (line[i] != ';')
				i++;
			i++;
			coord.y = atof(&line[i]);
			while (line[i] != ';')
				i++;
			i++;
			coord.z = atof(&line[i]);
			done = true;
		}
		i++;
	}
	return (coord);
}

double		get_line_double(char const *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '{')
			return (atof(&line[i + 1]));
		i++;
	}
	return (0);
}
