#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include <string.h>
# include <errno.h>

# define BUFF_SIZE 2048

int				get_next_line(const int fd, char **line);
typedef struct	s_gnl
{
	int		fd;
	char	*buff;
	int		nb_l;
	int		index;
	int		line_size;
	int		nb_call;
	int		ret;
}				t_gnl;

#endif

