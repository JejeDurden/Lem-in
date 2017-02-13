/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:26:58 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/09 14:02:34 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1b != *s2b)
			return (*s1b - *s2b);
		s1b++;
		s2b++;
		n--;
	}
	return (0);
}
