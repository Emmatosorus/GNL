/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:59:36 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/04 16:40:05 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char			*get_next_line(int fd);
static char		*get_line(char *buf);
static size_t	ft_linelen(char *str);
static int		add_saved(char *buf, char *str);

static char	*g_saved;
g_saved = NULL;

#endif