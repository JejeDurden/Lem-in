/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:17:07 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/13 08:34:57 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	tmp = malloc(sizeof(ptr) * size);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, ptr, size);
	free(ptr);
	return (tmp);
}
