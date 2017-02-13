/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_hashlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:42:47 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/10 15:22:03 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_hashlist		*ft_new_hashlist(t_room *room)
{
	t_hashlist		*new;

	if ((new = ft_memalloc(sizeof(t_hashlist))) == NULL)
		return (NULL);
	if ((new->room = ft_memalloc(sizeof(t_hashlist))) == NULL)
		return (NULL);
	new->next = NULL;
	new->room = room;
	return (new);
}
