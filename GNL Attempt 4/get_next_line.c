/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/12 16:25:47 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (1);
}

void	ft_strcpy(char *dest, char *src, size_t dest_start, size_t src_start)
{
	while (src[src_start])
	{
		dest[dest_start] = src[src_start];
		src_start++;
		dest_start++;
		if (src[src_start] == '\0' && src[src_start + 1] == '\0')
			dest[src_start + 1] = '\0';
	}
	dest[src_start] = '\0';
}

static ssize_t	check_saved(char *saved)
{
	ssize_t	i;

	i = 0;
	if (saved[i] == '\0' && saved[i + 1] == '\0')
		return (-1);
	while (saved[i] && saved[i] != '\n')
		i++;
	return (i);
}

static char	*case_manager(ssize_t res, int fd, char *saved)
{
	char	*n_save;
	char	*line;
	char	*rest;

	if (res == -1)
	{
		n_save = get_file(fd, saved);
		res = check_saved(n_save);
	}
	if (!n_save)
		return (NULL);
	line = get_line(res, saved);
	save_rest(res, saved, n_save);
	if (!line || !rest)
	{
		ft_free(n_save, NULL);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	ssize_t	res;
	static char	saved[BUFFER_SIZE + 1] = "\0";

	if (BUFFER_SIZE == 0)
		return (NULL);
	res = -1;
	while (res < 0)
	{
		res = check_saved(saved);
		line = case_manager(res, fd, saved);
		if (!line)
			return (NULL);
	}
	return (line);
}
