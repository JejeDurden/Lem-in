/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:25:32 by jdesmare          #+#    #+#             */
/*   Updated: 2016/11/10 10:05:37 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memzone;

	memzone = malloc(sizeof(char) * size);
	if (!memzone)
		return (NULL);
	return (ft_memset(memzone, 0, size));
}
