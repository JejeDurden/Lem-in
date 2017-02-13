/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:36:01 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/31 10:32:05 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_nb(long long int nb)
{
	int				len;
	long long int	n;

	len = 0;
	n = nb;
	if (nb < -9223372036854775807)
		return (20);
	if (nb == 0)
		return (1);
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
