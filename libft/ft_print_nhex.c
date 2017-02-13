/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:06:54 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/31 10:30:50 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nhex(unsigned long long int nb, int i)
{
	char	*str;

	str = "0123456789abcdef";
	while (i > 0)
	{
		if (nb >= 16)
		{
			ft_putchar(str[nb % 16]);
			nb /= 16;
		}
		else
			ft_putchar(str[nb]);
		i--;
	}
}
