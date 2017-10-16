/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:54:02 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/08 20:02:20 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	len = ft_strlen(s2);
	if (!len)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		n = 0;
		while (s1[i + n] == s2[n])
		{
			if (n == len - 1)
				return ((char *)&s1[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}
