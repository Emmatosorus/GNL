/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/13 18:43:24 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buf(char *buffer, char *line, int fd)
{
	char	*total;

	total = ft_strjoin(line, buffer);
	if (!total)
		return (free(line), NULL);
	free(line);
	line = total;
	return (line);
}

char	*get_line(char *buffer, char *line, ssize_t stat)
{
	char	*total;
	char	*tmp2;
	ssize_t	i;
	size_t	cr_p;

	total = ft_strjoin(line, buffer);
	if (!total)
		return (free(line), NULL);
	cr_p = check_str(total, stat);
	tmp2 = ft_calloc(cr_p + 2, sizeof(char));
	if (!tmp2)
		return (free(total), free(line), NULL);
	i = -1;
	while (total[++i] && i <= cr_p)
		tmp2[i] = total[i];
	cr_p = check_str(buffer, stat) + 1;
	if (cr_p != BUFFER_SIZE && BUFFER_SIZE != 1)
		buffer = ft_memmove(buffer, buffer + cr_p, ft_strlen(buffer + cr_p));
	else
		buffer[0] = 0;
	free(line);
	line = tmp2;
	return (free(total), line);
}

ssize_t	check_str(char *str, ssize_t stat)
{
	ssize_t	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (stat == -3)
		return (i - 1);
	if (str[i] == '\0')
		return (-2);
	return (i);
}

char	*case_manager(ssize_t *state, int fd, char *buffer, char *line)
{
	ssize_t	tmp;

	if (state[0] == -1)
	{
		tmp = read_file(fd, buffer, line);
		if (tmp == -1)
			return (free(line), NULL);
	}
	else
	{
		if (state[0] == -2)
		{
			line = save_buf(buffer, line, fd);
			tmp = read_file(fd, buffer, line);
			if (tmp == -1)
				return (free(line), NULL);
		}
		else
			line = get_line(buffer, line, state[0]);
		if (!line)
			return (NULL);
	}
	if (tmp == -2 || tmp == -3)
		state[0] = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		state[1];
	static char	buffer[BUFFER_SIZE + 1] = "\0";

	if (read(fd, &line, 0) < 0 || BUFFER_SIZE == 0)
		return (NULL);
	state[0] = -1;
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	while (state[0] < 0)
	{
		state[0] = check_str(buffer, state[0]);
		line = case_manager(state, fd, buffer, line);
		if (!line)
			return (NULL);
		if (state[0] == -2 && buffer[0] == '\0')
			return (free(line), NULL);
	}
	return (line);
}
