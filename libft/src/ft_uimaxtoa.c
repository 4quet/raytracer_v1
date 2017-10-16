/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:32:53 by lfourque          #+#    #+#             */
/*   Updated: 2015/02/11 16:34:03 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa(uintmax_t n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_uimaxlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (i < len)
	{
		str[len - i - 1] = ('0' + n % 10);
		n /= 10;
		i++;
	}
	return (str);
}
