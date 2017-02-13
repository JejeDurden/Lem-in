/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:23:26 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/28 19:28:47 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(unsigned long long int nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex(nb / 16);
	ft_putchar(str[nb % 16]);
}
