/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/11 18:53:38 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (g_save)
		free(g_save);
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

static ssize_t	check_g_save(void)
{
	ssize_t	i;

	if (!g_save)
		return (-2);
	i = 0;
	while (g_save[i] && g_save[i] != '\n')
		i++;
	if (g_save[i] == '\0' && g_save[i + 1] == '\0')
		return (-1);
	return (i);
}

static char	*case_manager(ssize_t res, int fd)
{
	char	*tmp;

	if (res == -2)
	{
		tmp = create_g_save();
		g_save = tmp;
	}
	else if (res == -1)
	{
		tmp = get_file(fd);
		g_save = tmp;
	}
	else
	{
		tmp = get_line(res);
		g_save = get_rest(res);
	}
	if (!tmp || !g_save)
	{
		ft_free(tmp, NULL);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*line;
	ssize_t	res;

	if (BUFFER_SIZE == 0)
	{
		ft_free(NULL, NULL);
		return (NULL);
	}
	res = -1;
	while (res < 0)
	{
		res = check_g_save();
		line = case_manager(res, fd);
		if (!line)
			return (NULL);
	}
	return (line);
}
