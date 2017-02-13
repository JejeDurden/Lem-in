/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:20:09 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 09:06:51 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		write_stdout(t_room *tmp, t_struct *pos, int i)
{
	if (tmp->child[i]->ant > 0 && tmp->child[i]->ant < pos->ant_total + 1)
	{
		ft_putchar('L');
		ft_putnbr(tmp->child[i]->ant);
		ft_putchar('-');
		ft_putstr(tmp->name);
		ft_putchar(' ');
		tmp->ant = tmp->child[i]->ant;
		if (ft_strcmp(pos->start->name, tmp->child[i]->name) != 0)
			tmp->child[i]->ant = 0;
	}
}

static int		u(char *n1, char *n2)
{
	return ((ft_strcmp(n1, n2) == 0));
}

void			move_ants(t_struct *pos)
{
	int			i;
	t_room		*tmp;
	char		*prev;

	pos->start->ant = 1;
	while (pos->end->ant != pos->ant_total)
	{
		tmp = pos->end;
		prev = "\n";
		while (ft_strcmp(pos->start->name, tmp->name) != 0)
		{
			i = -1;
			while (++i < tmp->child_nb && !u(pos->start->name, tmp->name))
			{
				if (tmp->child[i]->path == 1 && !u(tmp->child[i]->name, prev))
				{
					write_stdout(tmp, pos, i);
					prev = tmp->name;
					tmp = tmp->child[i];
				}
			}
		}
		ft_putchar('\n');
		pos->start->ant++;
	}
}
