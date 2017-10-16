/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:47 by lfourque          #+#    #+#             */
/*   Updated: 2015/01/28 13:40:16 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		index;
	int		len;
	char	*str;

	i = 0;
	index = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	index = i;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	while (s[--i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len < 0)
		len = 0;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	str = ft_strsub(s, index, len);
	return (str);
}
