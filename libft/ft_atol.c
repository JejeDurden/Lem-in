/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:12:26 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/02 17:07:12 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atol(const char *nptr)
{
	int				i;
	int				offset;
	long int		res;

	res = 0;
	offset = 0;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r' ||
				nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			offset = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (offset == 1)
		res *= -1;
	return (res);
}
