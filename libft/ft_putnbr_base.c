/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:22:54 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/30 16:36:54 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long int nb, int base)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (base == 10)
		ft_putnbr(nb);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
		}
		if (nb >= base)
			ft_putnbr_base(nb / base, base);
		ft_putchar(str[nb % base]);
	}
}
