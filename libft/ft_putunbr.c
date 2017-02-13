/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:07:48 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/30 18:22:28 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(long long int n)
{
	unsigned int		max;

	max = 4294967295;
	if (n == max || n < 0)
		ft_putstr("4294967295");
	else if (n <= max && n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
