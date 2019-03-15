#include "get_next_line.h"
#include "./libft/includes/libft.h"

int		main()
{
	char 	*line;
	int		res;

	int fd = open("test", O_RDWR);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		//printf("%s, %d\n", line, res);
		ft_strdel(&line);
	}
	//res = get_next_line(fd, &line);
	//printf("%s, %d\n", line, res);
	//ft_strdel(&line);	
	//close(fd);
	char *line2; 
	int fd2 = open("test2", O_RDWR);
	while ((res = get_next_line(fd2, &line2)) > 0)
	{
		printf("%s, %d\n", line2, res);
		ft_strdel(&line2);
	}
	//res = get_next_line(fd, &line);
	//printf("%s, %d\n", line, res);
	ft_strdel(&line);
	close(fd2);
	close(fd);
	return (0);
}
