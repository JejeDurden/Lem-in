/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 13:52:01 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/12 15:27:07 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_queue(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	*node = tmp->next;
	free(tmp);
}

t_node		*add_queue(t_node *node, t_room *room)
{
	t_node		*new;
	t_node		*tmp;

	tmp = node;
	if ((new = ft_memalloc(sizeof(t_node))) == NULL)
		return (NULL);
	if ((new->room = ft_memalloc(sizeof(t_room))) == NULL)
		return (NULL);
	new->room = room;
	new->next = NULL;
	if (tmp == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (node);
}
