/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:37:15 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/08 17:38:23 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (&str[i]);
			i++;
		}
		if (c == 0)
			return (&str[i]);
	}
	return (NULL);
}
