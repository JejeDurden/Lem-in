/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:29:18 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/07 14:42:13 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = ft_strnew(n);
	if (temp)
	{
		temp = ft_memcpy(temp, src, n);
		dest = ft_memcpy(dest, temp, n);
	}
	free(temp);
	return (dest);
}
