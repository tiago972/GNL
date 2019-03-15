#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include "sys/stat.h"
int		main()
{
	char 	*line;
	int		res;

	int fd = open("test", O_RDWR);
	struct stat stat1, stat2;
    if(fstat(fd, &stat1) < 0) return -1;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		//printf("%s, %d\n", line, res);
		ft_strdel(&line);
	}
	//res = get_next_line(fd, &line);
	//printf("%s, %d\n", line, res);
	//ft_strdel(&line);	
	close(fd);
	char *line2; 
	int fd2 = open("test2", O_RDWR);
	if(fstat(fd2, &stat2) < 0) return -1;
	if 	((stat1.st_dev == stat2.st_dev) && (stat1.st_ino == stat2.st_ino))
		printf("?????\n");
	while ((res = get_next_line(fd2, &line2)) > 0)
	{
		printf("%s, %d\n", line2, res);
		ft_strdel(&line2);
	}
	//res = get_next_line(fd, &line);
	//printf("%s, %d\n", line, res);
	ft_strdel(&line);
	close(fd2);
	//close(fd);
	return (0);
}
