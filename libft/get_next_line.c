/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:24:39 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/10 09:51:07 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_return(char *readfile, char **line)
{
	char	*temp;

	temp = ft_strchr(readfile, '\n');
	if (temp != NULL)
	{
		*line = ft_strcdup(readfile, '\n');
		ft_strcpy(readfile, temp + 1);
		return (1);
	}
	else if (ft_strlen(readfile) > 0)
	{
		*line = ft_strdup(readfile);
		*readfile = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*readfile = NULL;

	if (fd < -0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(readfile))
		readfile = ft_strnew(0);
	while (!(ft_strchr(readfile, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_return(readfile, line));
		buf[ret] = '\0';
		temp = ft_strjoin(readfile, buf);
		free(readfile);
		readfile = temp;
	}
	return (ft_return(readfile, line));
}
