#include "get_next_line.h"

int		ft_read(const int fd, char **res)
{
	char		*join_tmp;
	char		tmp_buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, tmp_buff, BUFF_SIZE)
	tmp_buff[ret] = '\0';
	join_tmp = ft_strjoin(*res, tmp_buff);
	res = ft_realloc(*res, ft_strlen(join_tmp) + 1);
	ft_strcpy(*res, join_tmp);
	free(join_tmp);
	if (ret < 0)
		return (-1);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	char			*res;

	if (fd == -1 || !line)
		return (-1);
	if (!(res = ft_strnew((size_t)BUFF_SIZE)))
		return (0);
	ft_read(fd, &res);
	//changer l idee car si fonction appelee qu une fois : fuite de mémoire
	//meilleure idee : lire de la tille de buffisize et si un backslash n est present < au nbre d'appel de la fonction: break et récupérer la ligne
	free(res);
	return (1);
}
