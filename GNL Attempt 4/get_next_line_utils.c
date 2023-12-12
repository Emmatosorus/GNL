/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:58:13 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/12 15:10:37 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_len(char *str, size_t start)
{
	size_t	i;

	i = start;
	while (str[i])
		i++;
	return (i);
}

char	*get_file(int fd, char *saved)
{
	char	buf[BUFFER_SIZE + 1];
	char	*new_s;
	size_t	saved_len;
	size_t	read_len;

	read_len = read(fd, buf, BUFFER_SIZE);
	if (read_len == -1)
		return (NULL);
	if (buf[0] == '\0')
		return (NULL);
	buf[read_len] = '\0';
	saved_len = get_len(saved, 0);
	new_s = (char *)malloc(((BUFFER_SIZE + saved_len) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strcpy(new_s, saved, 0, 0);
	ft_strcpy(new_s, buf, saved_len, 0);
	return (new_s);
}

char	*get_line(ssize_t res, char *saved)
{
	char	*line;

	line = (char *)malloc((res + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[res + 1] = '\0';
	while (res >= 0)
	{
		line[res] = saved[res];
		res--;
	}
	return (line);
}

void	save_rest(ssize_t res, char *saved, char *rest)
{
	size_t	rest_len;
	size_t	i;

	rest_len = get_len(saved, res + 1);
	i = 0;
	while (rest_len++ < BUFFER_SIZE + 1)
	{
		saved[i++] = rest[rest_len];
	}
}
