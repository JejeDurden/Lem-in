/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lunb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:01:51 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/31 10:41:19 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_lunb(unsigned long long int nb)
{
	int			len;

	len = 0;
	if (nb == 0)
		return (1);
	if ((long long int)nb < 0)
		return (20);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
