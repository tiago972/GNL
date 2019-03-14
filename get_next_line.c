#include "get_next_line.h"

int			debog(t_list **begin_list)
{
	t_list	*tmp;
	t_gnl	*debog;
	int	i = 0;
	if (!begin_list)
		return (0);
	tmp = *begin_list;
	debog = (t_gnl *)(tmp->content);
	while (tmp)
	{	
		printf("DANS LA LISTE FD %d  nb lines %d, nb_call %d, index %d, line_size %d\n", debog->fd, debog->nb_l, debog->nb_call , debog->index, debog->line_size);
		tmp = tmp->next;
		i++;
	}
	printf("nb dans la liste %d\n", i);
	return (i);
}

static	char	*ft_readfile(int fd, char *buff, int *ret)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(BUFF_SIZE);
	while ((*ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp2 = ft_strjoin(buff, tmp);
		ft_strdel(&buff);
		buff = strdup(tmp2);
		ft_strdel(&tmp2);
	}
	ft_strdel(&tmp);
	return (buff);
}

static int		ft_line_joker(char *str, int op)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			count++;
			if (op == 1)
				return (i);
		}
		i++;
	}
	return (count);
}

static t_gnl	*ft_initialize(t_list **begin_list, int fd)
{
	t_list	*tmp;
	t_gnl	new;

	tmp = *begin_list;
	while (tmp)
	{
		if (((t_gnl *)(tmp->content))->fd == fd)
			return ((t_gnl *)tmp->content);
		tmp = tmp->next;
	}
	ft_memset(&new, 0, sizeof(new));
	new.fd = fd;
	new.buff = ft_strnew(BUFF_SIZE);
	new.buff = ft_readfile(fd, new.buff, &(new.ret));
	new.nb_l = ft_line_joker(new.buff, 0);
	tmp = ft_lstnew(&new, sizeof(new));
	ft_lstadd(begin_list, tmp);
	return ((t_gnl *)(tmp->content));
}

static	void	ft_del(t_list **begin_list, int fd)
{
	t_list *tmp;
	t_gnl 	*del;
	t_list	*tmp2;

	tmp2 = *begin_list;
	while (tmp2)
	{
		del = ((t_gnl *)(*begin_list)->content);
		if (del->fd == fd)
			break ;
		tmp2 = tmp2->next;
	}
	if (!tmp2)
		return ;
	tmp = tmp2->next;
	ft_memset(del, 0, sizeof(*del));
	ft_strdel(&(del->buff));
	ft_memdel(&del);
	ft_memdel(&tmp2);
	*begin_list = tmp;
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*elem = NULL;
	t_gnl			*current;
	t_list			**begin_list;

	if (fd < 0 || !line)
		return (-1);
	begin_list = &elem;
	current = ft_initialize(begin_list, fd);
	//debog(&begin_list);
	if (current->ret == -1)
		return (-1);
	current->nb_call++;
	if (current->nb_call > 1)
		current->index = current->index + current->line_size + 1;
	current->line_size = ft_line_joker(current->buff + current->index, 1);
//	printf("CURRENT lines %d, nb_call %d, index %d, line_size %d, BUFF \n%s\n", current->nb_l, current->nb_call , current->index, current->line_size, current->buff);
	*line = ft_strsub(current->buff, current->index, current->line_size);
	if (current->nb_call <= current->nb_l)
	{
		if (current->nb_call == current->nb_l)
			ft_del(begin_list, fd);
		return (1);
	}
	return (0);
}
