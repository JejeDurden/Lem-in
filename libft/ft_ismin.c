/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:09:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/27 10:56:33 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ismin(int *tab, int size)
{
	int		min;
	int		i;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}
