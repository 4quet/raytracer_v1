/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:46:12 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/08 20:51:13 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s1 + i) = *(unsigned char *)(s2 + i);
		if (*(unsigned char *)(s2 + i) == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
