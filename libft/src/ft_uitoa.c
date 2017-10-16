/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:34:47 by lfourque          #+#    #+#             */
/*   Updated: 2015/01/28 13:40:49 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_uintlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[len - i - 1] = ('0' + n % 10);
		n = n / 10;
		i++;
	}
	return (str);
}
