#include "get_next_line.h"

int		main()
{
	int	fd;
	char	*line;
	int		i = -1;

	fd = open("test", O_RDONLY);
	//while (++i < 6)
		get_next_line(fd, &line);
	close(fd);
	return (0);
}
