/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:36:14 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/12 17:47:11 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int				ft_get_com(char *line, t_struct *pos)
{
	if (line[0] == '#')
	{
		if (ft_strcmp("##start", line) == 0)
			pos->flag = 1;
		else if (ft_strcmp("##end", line) == 0)
			pos->flag = 2;
		return (1);
	}
	return (-1);
}

int				ft_get_ant(char *line, t_struct *pos)
{
	int		i;
	int		flag;

	i = 0;
	if (line[i] == '-' || line[i] == '+' || !ft_isdigit(line[i]))
		return (-1);
	i++;
	flag = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			flag = 1;
		i++;
	}
	pos->ant_total = ft_atoi(line);
	if (pos->ant_total > 0 && flag == 0)
		return (1);
	return (-1);
}

t_room			*ft_parse_room(t_room *room, char *line, t_hashtable *hashtable)
{
	int			i;
	int			space;

	i = -1;
	space = 0;
	if (line[0] == 'L')
		return (NULL);
	while (ft_isspace(line[++i]) == 0 && line[i] != '\0')
	{
		if (i <= BUF_SZ && ft_isascii(line[i]) && line[i] != '-')
			room->name[i] = line[i];
		else
			return (NULL);
	}
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			space++;
		else if (!ft_isdigit(line[i]))
			return (NULL);
		i++;
	}
	if (space != 2 || hash_get(hashtable, room->name) != NULL)
		return (NULL);
	return (room);
}

static int		hash_place_room(t_hashtable *hashtable, t_room *room)
{
	int			i;
	t_hashlist	*new;

	if ((new = ft_new_hashlist(room)) == NULL)
		return (-1);
	i = ft_hash(room->name);
	new->next = hashtable->tab[i];
	hashtable->tab[i] = new;
	return (1);
}

int				ft_get_room(char *line, t_struct *pos, t_hashtable *hashtable)
{
	t_room		*room;

	if (ft_get_com(line, pos) == 1)
		return (1);
	if ((room = ft_memalloc(sizeof(t_room))) == NULL)
		return (-1);
	room->nb_max = 32;
	if ((room->child = ft_memalloc(sizeof(t_room) * room->nb_max)) == NULL)
		return (-1);
	if ((room = ft_parse_room(room, line, hashtable)) == NULL)
		return (-1);
	if (pos->flag == 1)
		pos->start = room;
	else if (pos->flag == 2)
		pos->end = room;
	if (pos->flag != 0)
		pos->flag = 0;
	return (hash_place_room(hashtable, room));
}
