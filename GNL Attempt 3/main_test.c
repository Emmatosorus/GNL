#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	char	*filename = "/home/epolitze/Documents/42/GNL/GNL Attempt 3/test.txt";
	int		fd = open(filename, O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}