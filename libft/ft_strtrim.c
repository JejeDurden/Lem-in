/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:42:19 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/09 15:31:05 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	min;
	char	*empty;

	i = 0;
	if (!s)
		return (NULL);
	empty = (char *)malloc(sizeof(char));
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	min = i;
	i = ft_strlen(s);
	if (min == i)
		return (empty);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	i = i - min;
	return (ft_strsub(s, min, i));
}
