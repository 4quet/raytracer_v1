/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:20:07 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/06 12:48:58 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *)s2;
	dst = (char *)s1;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return ((void *)dst);
}
