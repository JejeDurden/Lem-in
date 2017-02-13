/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnwlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:23:50 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/06 11:27:22 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnwlen(const wchar_t *str, int n)
{
	int		i;

	i = 0;
	if (str && n != 0)
	{
		while (*str != '\0' && n >= ft_char_size(*str))
		{
			n -= ft_char_size(*str);
			i += ft_char_size(*str);
			str++;
		}
	}
	return (i);
}
