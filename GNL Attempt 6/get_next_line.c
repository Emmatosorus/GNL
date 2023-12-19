/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/19 15:05:02 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(int fd, char *buffer, ssize_t *read_len)
{
	char	*line;
	size_t	buf_len;

	buf_len = ft_strlen(buffer);
	line = ft_calloc(buf_len + BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (buffer[0] == '\0')
		*read_len = read(fd, line, BUFFER_SIZE);
	else
	{
		ft_strncpy(line, buffer, ft_strlen(buffer));
		return (line);
	}
	if (*read_len == 0)
		return (free(line), NULL);
	return (line);
}

char	*read_more(int fd, char *line, ssize_t *read_len)
{
	size_t	line_len;
	char	*new_line;

	line_len = ft_strlen(line);
	new_line = ft_calloc(line_len + BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	ft_strncpy(new_line, line, line_len);
	*read_len = read(fd, new_line + line_len, BUFFER_SIZE);
	free(line);
	line = new_line;
	return (line);
}

char	*split_line(char *line, char *buffer)
{
	ssize_t	cr_pos;
	char	*new_line;
	int		last;

	cr_pos = ft_strchr(line, '\n') + 1;
	last = 0;
	if (cr_pos == 0)
	{
		cr_pos = ft_strlen(line) + 1;
		last = 1;
	}
	new_line = ft_calloc(cr_pos + 1, sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	ft_strncpy(new_line, line, cr_pos);
	ft_bzero(buffer, BUFFER_SIZE);
	if (last == 0)
		ft_strncpy(buffer, line + cr_pos, ft_strlen(line) - cr_pos);
	free(line);
	line = new_line;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		read_len;
	static char	buffer[BUFFER_SIZE + 1] = "\0";

	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	read_len = BUFFER_SIZE;
	while (ft_strchr(line, '\n') == -1)
	{
		if (!line)
			line = create_line(fd, buffer, &read_len);
		if (line && ft_strchr(line, '\n') == -1 && read_len > 0)
			line = read_more(fd, line, &read_len);
		if (line && (ft_strchr(line, '\n') != -1 || read_len >= 0))
			line = split_line(line, buffer);
		if (!line || read_len == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			return (free(line), NULL);
		}
		if (read_len == 0)
			return (line);
	}
	return (line);
}
