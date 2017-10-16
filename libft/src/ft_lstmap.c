/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:23:28 by lfourque          #+#    #+#             */
/*   Updated: 2014/12/05 19:34:00 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*begin_lst;

	if (!f || !lst)
		return (NULL);
	newlst = ft_lstnew(f(lst)->content, f(lst)->content_size);
	begin_lst = newlst;
	lst = lst->next;
	while (lst)
	{
		newlst->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		lst = lst->next;
		newlst = newlst->next;
	}
	return (begin_lst);
}
