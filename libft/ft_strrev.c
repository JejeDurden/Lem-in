/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:57:46 by jdesmare          #+#    #+#             */
/*   Updated: 2016/12/29 14:03:49 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	while (i <= len)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		i++;
		len--;
	}
	return (str);
}
