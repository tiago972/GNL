#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 2048

int		get_next_line(const int fd, char **line);

#endif

