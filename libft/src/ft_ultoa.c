/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 20:04:21 by lfourque          #+#    #+#             */
/*   Updated: 2015/01/26 20:06:15 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ultoa(unsigned long n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_ulonglen(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[len - i - 1] = ('0' + n % 10);
		n /= 10;
		i++;
	}
	return (str);
}
