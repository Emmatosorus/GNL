/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:55:33 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/07 10:46:48 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	*buf;
	char	*ptr;

	if (!fd || BUFFER_SIZE < 1)
	{
		free(g_saved);
		return (NULL);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
	{
		free(g_saved);
		return (NULL);
	}
	if (!read(fd, buf, BUFFER_SIZE))
	{
		ft_free(buf, ptr);
		return (NULL);
	}
	ptr = get_line(buf);
	if (!ptr)
	{
		ft_free(buf, ptr);
		return (NULL);
	}
	return (ptr);
}
