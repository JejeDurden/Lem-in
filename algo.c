/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 10:11:55 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 09:00:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		mark_shortest_path(t_struct *pos)
{
	int			i;
	t_room		*mark;

	mark = pos->end;
	mark->path = 1;
	while (mark->name != pos->start->name)
	{
		i = -1;
		while (++i < mark->child_nb)
		{
			if (mark->lvl == 1 && ft_strcmp(mark->child[i]->name,
													pos->start->name) == 0)
			{
				mark = mark->child[i];
				mark->path = 1;
				i = 0;
			}
			else if (mark->child[i]->lvl == mark->lvl - 1 && mark->lvl > 1)
			{
				mark = mark->child[i];
				mark->path = 1;
				i = 0;
			}
		}
	}
}

static int		find_end(t_node *node, t_struct *pos)
{
	while (node != NULL)
	{
		if (ft_strcmp(node->room->name, pos->end->name) == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

t_struct		*bfs(t_struct *pos)
{
	int		i;
	t_node	*queue;

	queue = add_queue(NULL, pos->start);
	while (queue != NULL && find_end(queue, pos) == 0)
	{
		i = -1;
		while (++i < queue->room->child_nb)
		{
			if (queue->room->child[i]->lvl == 0 && queue->room->child[i]->name
					!= pos->start->name)
			{
				queue = add_queue(queue, queue->room->child[i]);
				if (queue == NULL)
					return (NULL);
				queue->room->child[i]->lvl = queue->room->lvl + 1;
			}
		}
		delete_queue(&queue);
	}
	if (queue == NULL)
		return (NULL);
	while (queue != NULL)
		delete_queue(&queue);
	return (pos);
}

t_struct		*lem_in(t_struct *pos)
{
	if (pos->start->child_nb == 0 || pos->end->child_nb == 0)
		return (NULL);
	bfs(pos);
	if (pos == NULL)
		return (NULL);
	mark_shortest_path(pos);
	ft_putstr(pos->input);
	ft_putchar('\n');
	move_ants(pos);
	return (pos);
}
