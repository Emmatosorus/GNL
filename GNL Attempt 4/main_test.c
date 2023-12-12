#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	char	*filename = "/home/epolitze/Documents/GNL_folders/GNL_git/GNL Attempt 3/test.txt";
	int		fd = open(filename, O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}