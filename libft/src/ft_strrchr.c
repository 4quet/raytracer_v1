/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:49:48 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/07 16:43:18 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (str[i] != '\0')
	{
		if (str[(len - 1) - i] == c)
			return (&str[(len - 1) - i]);
		i++;
	}
	if (c == 0)
		return (&str[i]);
	return (NULL);
}
