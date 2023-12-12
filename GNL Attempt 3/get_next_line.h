/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:32 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/11 18:53:40 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
void	ft_free(char *buf, char *nbuf);
void	ft_strcpy(char *dest, char *src, size_t dest_start, size_t src_start);
char	*create_g_save(void);
char	*get_file(int fd);
char	*get_line(ssize_t res);
char	*get_rest(ssize_t res);

static char	*g_save = NULL;

#endif