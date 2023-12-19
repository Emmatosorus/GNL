/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:58:13 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/13 18:23:03 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	void			*ptr;
	unsigned char	*ptr2;
	size_t			n_x_s;

	n_x_s = n * size;
	if (n_x_s != 0 && n_x_s / n != size)
		return (NULL);
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (NULL);
	ptr2 = (unsigned char *)ptr;
	while (n_x_s > 0)
	{
		ptr2[n_x_s - 1] = '\0';
		n_x_s--;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (s1 && s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	return (dest);
}

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
	*destc = '\0';
	return (dest);
}

ssize_t	read_file(int fd, char *buffer, char *line)
{
	size_t	read_len;
	size_t	count;

	read_len = read(fd, buffer, BUFFER_SIZE);
	if (read_len < 0)
		return (-1);
	else if (read_len == 0)
	{
		count = 0;
		while (count < BUFFER_SIZE)
			buffer[count++] = '\0';
		return (-2);
	}
	else if (read_len != BUFFER_SIZE)
	{
		buffer[read_len] = '\0';
		return (-3);
	}
	buffer[read_len] = '\0';
	return (read_len);
}
