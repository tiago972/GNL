#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include "sys/stat.h"
int		main(int ac, char **av)
{
	char 	*line;
	int		res;
	int		fd;
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		while ((res = get_next_line(fd, &line)) > 0)
		{
			printf("res = %d, line = %s\n", res, line);
			ft_strdel(&line);		
		}
		i++;
	}
	return (0);
}
