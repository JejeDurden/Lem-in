/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:39:00 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/10 10:04:07 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		if (s[i] == c)
		{
			d[i] = s[i];
			d += i + 1;
			return (d);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
