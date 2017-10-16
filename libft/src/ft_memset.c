/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:33:42 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/06 11:51:37 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	value;
	size_t			i;

	str = (unsigned char *)b;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = value;
		i++;
	}
	return (b);
}
