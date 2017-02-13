/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:38:44 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/09 14:06:06 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
