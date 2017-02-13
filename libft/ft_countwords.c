/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:54:37 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/10 10:31:10 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}
