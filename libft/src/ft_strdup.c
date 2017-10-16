/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:14:39 by lfourque          #+#    #+#             */
/*   Updated: 2015/02/10 16:54:41 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	s2 = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		s2 = (char *)malloc(sizeof(*s2) * (len + 1));
		if (s2 == NULL)
			return (NULL);
		len = 0;
		while (s1[len] != '\0')
		{
			s2[len] = s1[len];
			len++;
		}
		s2[len] = '\0';
	}
	return (s2);
}
