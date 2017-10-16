/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:26:39 by lfourque          #+#    #+#             */
/*   Updated: 2015/01/28 13:38:35 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstring(char *str, int n, int neg, int len)
{
	int	i;

	i = 0;
	if (neg == 1)
	{
		str[0] = '-';
		i = 1;
	}
	while (i < len)
	{
		if (neg == 1)
			str[len - i] = ('0' - n % 10);
		else
			str[len - i - 1] = ('0' + n % 10);
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 0;
	len = 0;
	if (n < 0)
		neg = 1;
	len = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str = ft_fillstring(str, n, neg, len);
	return (str);
}
