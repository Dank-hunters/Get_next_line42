/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:39 by cguiot            #+#    #+#             */
/*   Updated: 2021/01/24 16:40:48 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1, int leaks);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
#endif
