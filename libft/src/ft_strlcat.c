/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:42:28 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/08 15:22:37 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	lens;
	size_t	lend;
	size_t	totallen;

	i = 0;
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (size < lend)
		return (size + lens);
	else
	{
		totallen = lend + lens;
		while (lend < (size - 1))
		{
			dst[lend] = src[i];
			lend++;
			i++;
		}
		dst[lend] = '\0';
		return (totallen);
	}
}
