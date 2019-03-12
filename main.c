#include "get_next_line.h"

int		main()
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = open("test", O_RDWR);
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "aaa"));
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "bbb"));
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "ccc"));
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "ddd"));
	close(p[1]);
	return (0);
}
