/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:09:56 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/08 09:56:08 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_cr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*line_add(char *buf, char *nbuf, int count)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	dest = malloc(((BUFFER_SIZE + 1) * count) * sizeof(char));
	if (!dest)
	{
		ft_free(buf, nbuf);
		return (NULL);
	}
	while (nbuf[i])
		dest[i] = nbuf[i++];
	j = i;
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		dest[j] = buf[i];
		i++;
	}
	dest[i] = '\0';
	free(nbuf);
	return (dest);
}

static char	*line_catcher(int fd)
{
	char	*buf;
	char	*nbuf;
	int		count;

	count = 1;
	nbuf = "";
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		ft_free(buf, nbuf);
		return (NULL);
	}
	buf[BUFFER_SIZE] = '\0';
	while (find_cr(buf) == 0)
	{
		if (!read(fd, buf, BUFFER_SIZE))
		{
			ft_free(buf, nbuf);
			return (NULL);
		}
		nbuf = line_add(buf, nbuf, count);
		count++;
	}
	free(buf);
	return (nbuf);
}



char	*get_next_line(int fd)
{
	char	*line;
	int		pos_of_cr;

	if (!read(fd, 0, 0) || BUFFER_SIZE == 0)
	{
		ft_free(NULL, NULL);
		return (NULL);
	}
	/*check_gsave*/
	line = line_catcher(fd);
	pos_of_cr = find_cr(line);
}
