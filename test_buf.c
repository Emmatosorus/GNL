/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:45:49 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/07 16:08:44 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_buf.h"

int	main(void)
{
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buf[BUFFER_SIZE] = '\0';
	if(buf[BUFFER_SIZE] == '\0')
		printf("YES!");
	else
		printf("%s\n", buf);
	free(buf);
}