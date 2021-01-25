/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:54:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/01/24 15:52:09 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*d;

	i = 0;
	c = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1 && s1[c])
		d[i++] = s1[c++];
	c = 0;
	while (s2 && s2[c])
	{
		d[i] = s2[c++];
		i++;
	}
	if (s1)
		free((char *)s1);
	s1 = NULL;
	d[i] = 0;
	return (d);
}

char	*ft_strdup(const char *s1, int leaks)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
	{
		if (leaks == 1)
			free((char *)s1);
		return (NULL);
	}
	str[0] = '\0';
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (leaks == 1)
	{
		free((char *)s1);
		s1 = NULL;
	}
	return (str);
}
