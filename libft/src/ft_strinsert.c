/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:11:55 by lfourque          #+#    #+#             */
/*   Updated: 2015/02/12 18:22:24 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char const *s1, char const *s2, unsigned int index)
{
	char	*ret;
	char	*temp1;
	char	*temp2;

	ret = NULL;
	if (s1 && s2)
	{
		temp1 = ft_strsub(s1, 0, index);
		temp2 = ft_strjoin(temp1, s2);
		free(temp1);
		temp1 = ft_strsub(s1, index, ft_strlen(s1) - index);
		ret = ft_strjoin(temp2, temp1);
		free(temp1);
		free(temp2);
	}
	return (ret);
}
