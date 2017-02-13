/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:31:54 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/30 19:33:31 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	if (str && n != 0)
	{
		while (str[i] != '\0' && i < n)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
