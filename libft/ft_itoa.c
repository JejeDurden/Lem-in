/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:23:30 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/13 12:25:58 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_nb(int nb)
{
	int				len;
	unsigned int	n;

	len = 1;
	n = nb;
	if (nb == 0)
		len = 2;
	if (nb < 0)
	{
		n = -nb;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				negative;
	unsigned int	nb;

	i = count_nb(n) - 1;
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	negative = n;
	str[i] = '\0';
	nb = n;
	if (n < 0)
		nb *= -1;
	if (n == 0)
		str[i - 1] = '0';
	while (nb > 0)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (negative < 0)
		str[0] = '-';
	return (str);
}
