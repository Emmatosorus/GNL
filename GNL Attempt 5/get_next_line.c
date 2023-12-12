/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:54 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/12 18:24:37 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buf(char *buffer, char *line, int fd)
{
	char	*total;

	total = ft_strjoin(line, buffer);
	free(line);
	if (!total)
		return (NULL);
	line = total;
	return (line);
}

char	*get_line(char *buffer, char *line)
{
	char	*total;
	char	*tmp2;
	size_t	i;
	size_t	cr_pos;

	total = ft_strjoin(line, buffer);
	if (!total)
		return (NULL);
	cr_pos = check_str(total);
	tmp2 = ft_calloc(cr_pos + 2, sizeof(char));
	if (!tmp2)
	{
		free(total);
		return (NULL);
	}
	free(line);
	while (total[i] && i <= cr_pos)
		tmp2[i] = total[i++];
	cr_pos = check_str(buffer) + 1;
	buffer = ft_memmove(buffer, buffer + cr_pos, ft_strlen(buffer) - cr_pos);
	free(total);
	line = tmp2;
	return (line);
}

size_t	check_str(char *str)
{
	size_t i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	return(i);
}

char	*case_manager(ssize_t state, int fd, char *buffer, char *line)
{
	char	*tmp;
	char	*save;

	if (state == -1)
	{
		tmp = read_file();
		if (!tmp)
			return (NULL);
		return ("");
	}
	else
	{
		if (state + 1 == BUFFER_SIZE)
			line = save_buf(buffer, line, fd);
		else
			line = get_line(buffer, line);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	ssize_t	state;
	static char	buffer[BUFFER_SIZE + 1] = "\0";

	if (BUFFER_SIZE == 0)
		return (NULL);
	state = -1;
	while (state < 0)
	{
		state = check_str(buffer);
		line = case_manager(state, fd, buffer, line);
		if (!line)
			return (NULL);
	}
	return (line);
}
