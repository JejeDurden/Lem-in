/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:47:29 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/08 16:28:05 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*freshlist;

	if (lst)
	{
		freshlist = (t_list *)malloc(sizeof(lst));
		if (!freshlist)
			return (NULL);
		freshlist = f(lst);
		freshlist->next = ft_lstmap(lst->next, f);
		return (freshlist);
	}
	return (NULL);
}
