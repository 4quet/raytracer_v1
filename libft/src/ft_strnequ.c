/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:42:06 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/09 15:11:26 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (s1[i] != '\0' && i <= n - 1)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (i <= n - 1 && s1[i] != s2[i])
			return (0);
		return (1);
	}
	return (0);
}
