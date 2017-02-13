/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 08:47:37 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 08:14:52 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static int		etat_salle(char *line, t_struct *pos, t_hashtable *hashtable,
														t_etat etat)
{
	int		ret;

	ret = ft_get_room(line, pos, hashtable);
	if (ret < 0)
	{
		ret = ft_get_tube(line, hashtable);
		etat = ETAT_TUBE;
	}
	return (ret);
}

t_struct		*ft_get_infos(t_hashtable *hashtable, t_struct *pos)
{
	int			ret;
	t_etat		etat;
	char		*line;

	ret = 1;
	etat = ETAT_FOURMI;
	while (ret >= 0 && get_next_line(STDIN_FILENO, &line) > 0)
	{
		pos->input = ft_strjoin(pos->input, line);
		pos->input = ft_strjoin(pos->input, "\n");
		if (etat == ETAT_FOURMI)
		{
			ret = ft_get_ant(line, pos);
			etat = ETAT_SALLE;
		}
		else if (etat == ETAT_SALLE)
			ret = etat_salle(line, pos, hashtable, etat);
		else if (etat == ETAT_TUBE)
			ret = ft_get_tube(line, hashtable);
		free(line);
	}
	if (pos->start == NULL || pos->end == NULL || ret < 0)
		return (NULL);
	return (pos);
}
