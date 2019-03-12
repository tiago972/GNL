#include "get_next_line.h"

int		ft_isbackslashn(char *s)
{
	char	*cpy;

	cpy = s;
	while (*cpy++)
		if (*cpy == '\n')
			return (1);
	return (0);
}

int		ft_read(const int fd, char **res)
{
	char		*join_tmp;
	char		tmp_buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, tmp_buff, BUFF_SIZE);
	tmp_buff[ret] = '\0';
	join_tmp = ft_strjoin(*res, tmp_buff);
	*res = ft_realloc(*res, ft_strlen(join_tmp) + 1);
	ft_strcpy(*res, join_tmp);
	free(join_tmp);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	char	*res;
	int		ret;

	ret = 1;
	if (fd == -1 || !line)
		return (-1);
	if (!(res = ft_strnew((size_t)BUFF_SIZE)))
		return (0);
	while (ret > 0 && !ft_isbackslashn(res))
		ret = ft_read(fd, &res);
	if (ret >= 0)
	{
		res[ft_strlen(res) - 1] = '\0';
		*line = ft_strdup(res);
	}
	free(res);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return(0);
	return (-1);
}
