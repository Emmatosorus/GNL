/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:09:40 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/08 08:32:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *buf, char *nbuf)
{
	if (buf)
		free(buf);
	if (nbuf)
		free(nbuf);
	if (g_save)
		free(g_save);
}