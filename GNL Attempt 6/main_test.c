/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:15 by epolitze          #+#    #+#             */
/*   Updated: 2023/12/19 14:55:00 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*filename;
	int		fd;
	char	*str = "";
	int		i;

	i = 0;
	filename = "test2.txt";
	fd = open(filename, O_RDONLY);
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("line %d : %s\n", i, str);
		free(str);
		i++;
	}
	close(fd);
}
