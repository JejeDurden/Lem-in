/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:23:26 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/29 18:17:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_min(long long int nb, int base)
{
	char	*str;

	str = "0123456789abcdef";
	if (base == 10)
		ft_putnbr(nb);
	else
	{
		if (nb < 0 && base == 16)
			nb = 4294967295 + nb;
		if (nb < 0)
			nb = -nb;
		if (nb >= base)
			ft_putnbr_base_min(nb / base, base);
		ft_putchar(str[nb % base]);
	}
}
