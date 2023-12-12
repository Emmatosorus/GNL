/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:58:13 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/11 18:53:42 by epolitze         ###   ########.fr       */
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

char	*create_g_save(void)
{
	g_save = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!g_save)
		return (NULL);
	g_save[BUFFER_SIZE] = '\0';
	return (g_save);
}

char	*get_file(int fd)
{
	char	*buf;
	char	*new_g_s;
	size_t	g_save_len;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	g_save_len = get_len(g_save, 0);
	new_g_s = (char *)malloc(((BUFFER_SIZE + g_save_len) + 1) * sizeof(char));
	if (!new_g_s)
	{
		free(buf);
		return (NULL);
	}
	ft_strcpy(new_g_s, g_save, 0, 0);
	ft_strcpy(new_g_s, buf, g_save_len, 0);
	free(g_save);
	g_save = new_g_s;
	free(buf);
	return (g_save);
}

char	*get_line(ssize_t res)
{
	char	*line;

	line = (char *)malloc((res + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line[res + 1] = '\0';
	while (res >= 0)
	{
		line[res] = g_save[res];
		res--;
	}
	return (line);
}

char	*get_rest(ssize_t res)
{
	size_t	rest_len;
	char	*rest;

	rest_len = get_len(g_save, res + 1);
	rest = (char *)malloc((rest_len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	ft_strcpy(rest, g_save, 0, res + 1);
	free(g_save);
	g_save = rest;
	return (g_save);
}
