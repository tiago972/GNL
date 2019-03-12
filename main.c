#include "get_next_line.h"

int		main()
{
	char 	*line;
	int		i = -1;

	int fd = open("test", O_RDWR);
	while (++i < 6)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
