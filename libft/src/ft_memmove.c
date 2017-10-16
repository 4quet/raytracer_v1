/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:22:30 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/08 20:41:03 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s2;
	char	*tmp;

	i = 0;
	s2 = (char *)dst;
	tmp = ft_strdup(src);
	while (i < len)
	{
		s2[i] = tmp[i];
		i++;
	}
	return ((void *)dst);
}
