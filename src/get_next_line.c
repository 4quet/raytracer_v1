/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:15:09 by lfourque          #+#    #+#             */
/*   Updated: 2015/02/21 17:21:16 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_check_eof(char *buf)
{
	int		len;
	char	*ret;

	len = ft_strlen(buf);
	if (buf[len - 1] != '\n')
	{
		ret = ft_strjoin(buf, "\n");
		free(buf);
		return (ret);
	}
	else
		return (buf);
}

int		ft_check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_set_strings(char **old, t_data data)
{
	char	*line;
	int		len;

	len = ft_strlen(data.str);
	line = ft_strsub(data.str, 0, data.index);
	*old = ft_strsub(data.str, data.index + 1, len - data.index);
	free(data.str);
	return (line);
}

char	*ft_reset(t_data *data, char **old)
{
	char	*str;

	if (data->ret && data->ret < BUFF_SIZE)
		data->buf = ft_check_eof(data->buf);
	str = ft_strjoin(*old, data->buf);
	if (*old)
		free(*old);
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	t_data		data;
	static char	*old = NULL;

	data.loop = 1;
	if (!line || !(data.buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((data.ret = read(fd, data.buf, BUFF_SIZE)) || data.loop)
	{
		if (data.ret == -1)
			return (-1);
		data.buf[data.ret] = 0;
		data.str = ft_reset(&data, &old);
		if ((data.index = ft_check_new_line(data.str)) >= 0)
		{
			*line = ft_set_strings(&old, data);
			free(data.buf);
			return (1);
		}
		else
			old = ft_strdup(data.str);
		data.loop = (old[0]) ? 1 : 0;
		free(data.str);
	}
	free(data.buf);
	return (0);
}
