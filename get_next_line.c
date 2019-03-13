#include "get_next_line.h"

static size_t	ft_newstrlen(char *s)
{
	char	*cpy;

	cpy = s;
	while (*cpy && *cpy != '\n')
		cpy++;
	return (cpy - s);
}

static int		ft_get_line(int n_call, char *res, char **line)
{
	char	*cpy;
	int		count;

	cpy = res;
	count = 0;
	while (count < n_call - 1 && *cpy)
	{
		if (*cpy == '\n')
			count++;
		cpy++;
	}
	if (!(*line = ft_strnew(ft_newstrlen(cpy))))
		return (-1);
	ft_memcpy(*line, cpy,ft_newstrlen(cpy));
	return (1);
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

static int		ft_countlines(char *s)
{
	int		count;
	char	*cpy;

	cpy = s;
	count = 0;
	while (*cpy++)
		if (*cpy == '\n')
			count++;
	return (count);
}

int				get_next_line(const int fd, char **line)
{
	static char	*res = NULL;
	int			ret;
	int			count;
	static int	n_call = 0;

	count = -1;
	if (fd == -1 || !line)
		return (-1);
	n_call++;
	if (!res)
		if (!(res = ft_strnew(BUFF_SIZE)))
			return (-1);
	ret = ft_read(fd, &res);
	if (ret < 0)
		return (-1);
	if (ft_get_line(n_call, res, line) == -1)
		return (-1);
	count = ft_countlines(res);
	if (count + 1 <= n_call)
	{
		//ft_strclr(*line);
		//free(res);
		return(0);
	}
	return (1);
}
