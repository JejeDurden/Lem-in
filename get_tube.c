/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:40:10 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 08:48:45 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int				connection_is_set(t_room *room1, t_room *room2)
{
	int		i;
	int		j;

	i = 0;
	while (i < room1->child_nb)
	{
		j = 0;
		while (j < room2->child_nb)
		{
			if (room1->child[i] == room2 || room2->child[j] == room1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int				agrandir(t_room *room)
{
	room->nb_max *= 2;
	room->child = ft_realloc(room->child, room->nb_max * sizeof(t_room));
	if (room->child == NULL)
		return (-1);
	return (1);
}

static int		ft_set_conn(char *first, char *second, t_hashtable *hashtable)
{
	t_room			*room1;
	t_room			*room2;
	int				ret;

	room1 = hash_get(hashtable, first);
	room2 = hash_get(hashtable, second);
	if (room1 == NULL || room2 == NULL || connection_is_set(room1, room2) < 0)
		return (-1);
	if (room1->child_nb + 1 > room1->nb_max)
	{
		ret = agrandir(room1);
		if (ret == -1)
			return (-1);
	}
	if (room2->child_nb + 1 > room2->nb_max)
	{
		ret = agrandir(room2);
		if (ret == -1)
			return (-1);
	}
	room1->child[room1->child_nb++] = room2;
	room2->child[room2->child_nb++] = room1;
	return (1);
}

int				ft_get_tube(char *line, t_hashtable *hashtable)
{
	char	*s;

	if (ft_strcmp("##start", line) == 0 || ft_strcmp("##end", line) == 0)
		return (-1);
	else if (ft_get_com(line, NULL) == 1)
		return (1);
	else
	{
		s = strchr(line, '-');
		if (s == NULL)
			return (-1);
		*s = '\0';
		s++;
		return (ft_set_conn(line, s, hashtable));
	}
	return (1);
}
