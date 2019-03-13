#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# define BUFF_SIZE 2048

int				get_next_line(const int fd, char **line);
typedef struct	s_gnl
{
	int		fd;
	int		ret;
	char	*buff;

}				t_gnl;

#endif
