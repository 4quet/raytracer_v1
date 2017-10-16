/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:08:19 by lfourque          #+#    #+#             */
/*   Updated: 2014/11/10 11:35:47 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	if (alst)
	{
		while (*alst != NULL)
		{
			elem = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = elem;
		}
	}
}
