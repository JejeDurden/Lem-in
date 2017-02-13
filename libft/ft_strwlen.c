/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:57:46 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/01 13:22:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(const wchar_t *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i += ft_char_size(*s);
		s++;
	}
	return (i);
}
