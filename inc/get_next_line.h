/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:07:52 by lfourque          #+#    #+#             */
/*   Updated: 2015/02/21 17:48:28 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 8

typedef	struct	s_data
{
	int			ret;
	int			loop;
	int			index;
	char		*buf;
	char		*str;
}				t_data;

int				get_next_line(int const fd, char **line);

#endif
