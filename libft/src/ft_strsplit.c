/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:26:22 by lfourque          #+#    #+#             */
/*   Updated: 2015/04/04 17:39:45 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			n++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (n);
}

int		ft_wordlen(const char *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		a;
	int		i;
	int		len;

	i = 0;
	a = 0;
	len = ft_countwords(s, c);
	if (!len || !s || !s[0])
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[a] = ft_strsub(s, i, ft_wordlen(s, i, c));
			a++;
			i = i + ft_wordlen(s, i, c);
		}
		else
			i++;
	}
	tab[a] = 0;
	return (tab);
}
