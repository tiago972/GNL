#include "get_next_line.h"

int		main()
{
	char 	*line;
	int		res;

	int fd = open("test", O_RDWR);
	/*int i = -1;
	  while (++i < 2)
	  {
		get_next_line(fd, &line);
		//printf("%s", line);
		free(line);
		line = malloc(1);
	  }
	  free(line);*/
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("%s, %d\n", line, res);
		ft_strdel(&line);
	}
	close(fd);
	char *line2;
	int fd2 = open("test2", O_RDWR);
	while ((res = get_next_line(fd2, &line2)) > 0)
	{
		printf("%s, %d\n", line2, res);
		ft_strdel(&line2);
	}
	free(line2);
	close(fd2);
	return (0);
}
