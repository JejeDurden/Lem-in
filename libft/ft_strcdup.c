/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:41:02 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/13 08:34:43 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s) && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
