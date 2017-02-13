/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:45:14 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 10:05:29 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_hash(char *name)
{
	int		i;
	int		len;
	int		sum;

	i = 0;
	sum = 0;
	len = ft_strlen(name);
	while (i < len)
	{
		sum += name[i] * ft_power(7, i);
		i++;
	}
	sum %= HASH_SZ;
	return (sum);
}

t_room			*hash_get(t_hashtable *hashtable, char *name)
{
	t_hashlist		*list;
	int				i;

	i = ft_hash(name);
	list = hashtable->tab[i];
	while (list != NULL)
	{
		if (ft_strcmp(name, list->room->name) == 0)
			return (list->room);
		list = list->next;
	}
	return (NULL);
}

t_hashtable		*hash_create(void)
{
	t_hashtable		*hashtable;

	if ((hashtable = ft_memalloc(sizeof(t_hashtable))) == NULL)
		return (NULL);
	return (hashtable);
}

void			hash_delete(t_hashtable *hashtable)
{
	int			i;
	t_hashlist	*tmp;
	t_hashlist	*list;

	i = 0;
	while (i < HASH_SZ)
	{
		if (hashtable->tab[i] != NULL)
		{
			list = hashtable->tab[i]->next;
			free(hashtable->tab[i]);
			while (list)
			{
				tmp = list->next;
				free(list);
				list = tmp;
			}
		}
		i++;
	}
	free(hashtable);
}
