/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:46:41 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/06 10:25:12 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnwstr(wchar_t *str, int n)
{
	if (str && n != 0)
	{
		while (*str != '\0' && n > 0)
		{
			if (n >= ft_char_size(*str))
				ft_putwchar(*str);
			n -= ft_char_size(*str);
			str++;
		}
	}
}
