/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:48:48 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/10 10:37:29 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_countwords(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (count--)
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_wordlen(s, c);
		tab[i] = ft_strsub(s, 0, len);
		if (!tab[i])
			return (NULL);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
