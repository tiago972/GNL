#include "./get_next_line.h"

char	*ft_read(const int fd, char **res, int *ret)
{
	char		*join_tmp;
	char		tmp_buff[BUFF_SIZE + 1];

	*ret = read(fd, tmp_buff, BUFF_SIZE);
	tmp_buff[*ret] = '\0';
	join_tmp = ft_strjoin(*res, tmp_buff);
	*res = ft_realloc(*res, ft_strlen(join_tmp) + 1);
	ft_strcpy(*res, join_tmp);
	free(join_tmp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*res = "";
	int			ret;
	char		*tmp;

	(void)line;
	if (fd < 0 || !line || !(res = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ft_read(fd, &res, &ret);
	}
	return (ret);
}
