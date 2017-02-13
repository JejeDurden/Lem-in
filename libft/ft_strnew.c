/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:33:23 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/07 14:47:36 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (size > 0)
	{
		new[size] = '\0';
		size--;
	}
	new[size] = '\0';
	return (new);
}
