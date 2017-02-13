/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:37:12 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/31 10:30:28 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putoct(unsigned long long int nb)
{
	char	*str;

	str = "01234567";
	if (nb >= 8)
		ft_putoct(nb / 8);
	ft_putchar(str[nb % 8]);
}
