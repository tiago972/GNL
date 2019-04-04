#include "get_next_line.h"
#include "libft/includes/libft.h"

int		main()
{
	char *line;

	/*get_next_line(0, &line);
	  printf("%s", line);
	  ft_strdel(&line);*/
	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
