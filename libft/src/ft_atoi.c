/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:10:34 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/31 17:34:42 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	if (str)
	{
		while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
			i++;
		if (str[i] == '-')
		{
			sign = -sign;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + (str[i] - '0');
			i++;
		}
	}
	return (value * sign);
}
