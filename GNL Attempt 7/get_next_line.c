/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/19 16:30:46 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destc;
	unsigned char	*srcc;

	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (destc < srcc)
		while (n--)
			*destc++ = *srcc++;
	else
		while (n--)
			*(destc + n) = *(srcc + n);
	return (dest);
}

char	*read_more(int fd, char *line, char *buffer, ssize_t *read_len)
{
	ssize_t	llen;
	char	*new_line;

	llen = 0;
	if (line)
		llen = ft_strlen(line);
	new_line = ft_calloc(llen + BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	ft_strncpy(new_line, line, llen);
	ft_strncpy(new_line + llen, buffer, ft_strlen(buffer));
	*read_len = read(fd, buffer, BUFFER_SIZE);
	buffer[*read_len] = '\0';
	free(line);
	line = new_line;
	return (line);
}

char	*get_line_buf(char *line, char *buffer)
{
	ssize_t	cr_pos;
	ssize_t	llen;
	ssize_t	blen;
	char	*new_line;

	llen = 0;
	if (line)
		llen = ft_strlen(line);
	cr_pos = ft_strchr(buffer, '\n') + 1;
	new_line = ft_calloc(llen + cr_pos + 1, sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	ft_strncpy(new_line, line, llen);
	ft_strncpy(new_line + llen, buffer, cr_pos);
	blen = ft_strlen(buffer);
	ft_memmove(buffer, buffer + cr_pos, blen - cr_pos);
	blen = (blen - cr_pos);
	buffer[blen] = '\0';
	free(line);
	line = new_line;
	return (line);
}

char	*read_line(int fd, char *line, char *buffer, ssize_t *read_len)
{
	if (buffer[0] == '\0')
	{
		*read_len = read(fd, buffer, BUFFER_SIZE);
		if (*read_len < 1)
			return (free(line), NULL);
		buffer[*read_len] = '\0';
	}
	while (ft_strchr(buffer, '\n') == -1)
	{
		line = read_more(fd, line, buffer, read_len);
		if (!line || *read_len == -1)
			return (free(line), NULL);
		if (*read_len == 0)
			return (line);
	}
	line = get_line_buf(line, buffer);
	if (!line)
		return (NULL);
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
	if (ft_strchr(buffer, '\n') >= 0)
		line = get_line_buf(line, buffer);
	else
	{
		line = read_line(fd, line, buffer, &read_len);
		if (!line || read_len == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			return (free(line), NULL);
		}
	}
	return (line);
}