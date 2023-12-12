/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:58:59 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/07 10:56:08 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *buf, char *ptr)
{
	if (buf)
		free(buf);
	if (g_saved)
		free(g_saved);
	if (ptr)
		free(ptr);
}

static int	add_saved(char *buf, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!g_saved)
		while (buf && buf[i] != '\n')
			str[i] = buf[i++];
	else
	{
		while (g_saved && g_saved[i] != '\n')
			str[i++] = g_saved[j++];
		if (g_saved[j] == '\0')
		{
			j = 0;
			while (buf && buf[j] != '\n')
				str[i++] = buf[j++];
		}
	}
}

static size_t	ft_linelen(char *str)
{
	size_t	i;

	i = 0;
	if (!g_saved)
		while (str && str[i] != '\n')
			i++;
	else
	{
		while (g_saved && g_saved[i] != '\n')
			i++;
		if (g_saved[i] == '\0')
			while (str && str[i] != '\n')
				i++;
	}
	return (i + 1);
}

static char *save_rest()
{

}

static char	*get_line(char *buf)
{
	char	*str;
	size_t	len;

	len = ft_linelen(buf);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	add_saved(buf, str);
	/*Put what hasn't been added to str in g_save*/
	return (str);
}
