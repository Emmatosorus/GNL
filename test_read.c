#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, const char **av)
{
	if (!av[1])
		return (0);
	int i = atoi(av[1]);
	(void)ac;
	char *str = malloc(i + 1 * sizeof(char));
	if (!str)
		return (0);
	char *str2 = malloc(i + 1 * sizeof(char));
	if (!str2)
	{
		free(str);
		return(0);
	}
	char *filename = "/home/epolitze/Documents/42/GNL/prout.txt";
	int	fd = open(filename, O_RDONLY);
	read(fd, str, i);
	printf("String : %s\n", str);
	read(fd, str2, i);
	printf("String : %s\n", str2);
	close(fd);
	free(str);
	free(str2);
}