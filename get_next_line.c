#include "get_next_line.h"
/*
   static size_t	ft_newstrlen(char *s)
   {
   char	*cpy;

   cpy = s;
   while (*cpy && *cpy != '\n')
   cpy++;
   return (cpy - s);
   }

static void		ft_trim(char *s)
{
	char *cpy;

	cpy = s;
	while (*cpy)
	{
		if (*cpy == '\n')
			*cpy = '\0';
		cpy++;	
	}
}*/
static int		ft_get_line(char **res, char **line)
{
	char	*tmp;
	size_t	n;

	while (**res)
	{
		tmp = ft_strchr(*res, '\n');
		if (tmp != NULL)
			n = tmp - *res;
		else
			n = 0;
		if (n > 0)
		{
			if (!(*line = ft_strnew(n)))
				return (-1);
			*line = ft_memmove(*line, *res, n);
			ft_strcpy(*res, *res + n + 1);
		}
		else if (n == 0)
		{
			if (!(*line = ft_strnew(ft_strlen(*res))))
				return (-1);
			*line = ft_strcpy(*line, *res);
			ft_strcpy(*res, "\0");
		}
		if (*line)
			return (1);
	}
	return (-1);
}

static int		ft_read(const int fd, char **res)
{
	char		*join_tmp;
	char		tmp_buff[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, tmp_buff, BUFF_SIZE)) > 0)
	{
		tmp_buff[ret] = '\0';
		join_tmp = ft_strjoin(*res, tmp_buff);
		*res = ft_realloc(*res, ft_strlen(join_tmp) + 1);
		ft_strcpy(*res, join_tmp);
		free(join_tmp);
	}
	return (ret);
}
/*
   static int		ft_countlines(char *s)
   {
   int		count;
   char	*cpy;

   cpy = s;
   count = 0;
   while (*cpy++)
   if (*cpy == '\n')
   count++;
   if (*(cpy - 2) != '\n')
   count++;
   return (count);
   }
   */
int				get_next_line(const int fd, char **line)
{
	static char	*res = NULL;
	int			ret;
	static char	**tmp = NULL;

	if (fd == -1 || !line)
		return (-1);
	if (!res)
	{
		if (!(res = ft_strnew(BUFF_SIZE)))
			return (-1);
		tmp = &res;
	}
	ret = ft_read(fd, tmp);
	if (ret < 0)
		return (-1);
	if (ft_get_line(tmp, line) == -1)
		return (-1);
	if (*res == '\0')
	{	
		ft_strdel(&res);
		return(0);
	}
	return (1);
}
