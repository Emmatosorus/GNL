/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_buf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:47:16 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/07 15:55:11 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BUF_H
# define TEST_BUF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char			*get_next_line(int fd);

static char	*g_saved;

#endif