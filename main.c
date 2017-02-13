/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:41:02 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 11:18:56 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int		main(void)
{
	t_struct		*pos;
	t_hashtable		*hashtable;

	hashtable = hash_create();
	if ((pos = ft_memalloc(sizeof(t_struct))) == NULL)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	pos->input = ft_strnew(0);
	pos = ft_get_infos(hashtable, pos);
	hash_delete(hashtable);
	if (pos != NULL)
		pos = lem_in(pos);
	if (pos == NULL)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	free(pos);
	return (0);
}
