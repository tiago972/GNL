#include "get_next_line.h"

int		main()
{
	char 	*line;
	int		res;

	int fd = open("test", O_RDWR);
	while ((res = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
