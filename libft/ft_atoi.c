/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:19:50 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/24 14:12:01 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		offset;
	int		res;

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
