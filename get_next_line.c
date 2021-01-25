/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:54:37 by cguiot            #+#    #+#             */
/*   Updated: 2021/01/24 13:52:16 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	build(char **line, char **save)
{
	int	i;

	i = 0;
	while (line[0] && line[0][i])
	{
		if (line[0][i] == '\n')
		{
			line[0][i] = '\0';
			i++;
			if ((*save = ft_strdup(line[0] + i, 0)) == NULL)
				return (-1);
			if ((*line = ft_strdup(line[0], 1)) == NULL)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_free(char **str, int ret)
{
	if (!(*str == NULL))
	{
		free(str);
		*str = NULL;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (save)
	{
		*line = ft_strdup(save, 1);
		save = NULL;
	}
	while (ret > 0 && (ret = build(line, &save)) == 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_free(&save, -1));
		buff[ret] = '\0';
		if (!(*line = ft_strjoin(*line, buff)))
			return (ft_free(line, -1));
	}
	return (ret);
}
