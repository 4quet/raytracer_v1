/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:33:09 by lfourque          #+#    #+#             */
/*   Updated: 2015/01/28 13:39:12 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size < 1)
		return (NULL);
	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
