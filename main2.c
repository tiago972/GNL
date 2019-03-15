#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include "sys/stat.h"
int		main()
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
//	mt_assert(strcmp(line, "aaa") == 0);
//	mt_assert(gnl_ret == 0 || gnl_ret == 1);
	return (0);
}
