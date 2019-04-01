/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:07:47 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 17:21:25 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			if (op == 3)
				return (1);
		}
		i++;
	}
	if (op == 3)
		return (0);
	if (op == 1)
		return (i);
	if (i > 0 && str[i - 1] != '\n')
		count++;
	return (count);
}

static	char	*ft_readfile(int fd, t_gnl *ptr)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(BUFF_SIZE);
	while ((ptr->ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ptr->ret] = '\0';
		tmp2 = ft_strjoin(ptr->buff, tmp);
		ft_strdel(&(ptr->buff));
		ptr->buff = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		if (ft_line_joker((ptr->buff + ptr->index), 3))
			break ;
	}
	ft_strdel(&tmp);
	return (ptr->buff);
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
	ft_memset(&new, 0, sizeof(t_gnl));
	new.fd = fd;
	new.buff = ft_strnew(BUFF_SIZE);
	new.buff = ft_readfile(fd, &new);
	tmp = ft_lstnew(&new, sizeof(t_gnl));
	ft_lstadd(begin_list, tmp);
	return ((t_gnl *)(tmp->content));
}

static	int		ft_del(t_list **begin_list, int fd, int opt)
{
	t_list	*tmp;
	t_gnl	*del;
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
		return (0);
	tmp = tmp2->next;
	ft_strdel(&(del->buff));
	ft_memdel(&del);
	ft_memdel(&tmp2);
	*begin_list = tmp;
	return (opt == -1 ? -1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*begin_list = NULL;
	t_gnl			*current;

	if (fd < 0 || !line)
		return (-1);
	current = ft_initialize(&begin_list, fd);
	if (!current || current->ret == -1)
	{
		ft_strdel(line);
		return (ft_del(&begin_list, fd, -1));
	}
	if (++(current->nb_call) > 1)
	{
		current->index = current->index + current->line_size + 1;
		current->buff = ft_readfile(current->fd, current);
	}
	if (((int)ft_strlen(current->buff)) > current->index)
	{
		current->line_size = ft_line_joker(current->buff + current->index, 1);
		*line = ft_strsub(current->buff, current->index, current->line_size);
	}
	if (current->ret == 0)
		current->nb_l = ft_line_joker(current->buff, 0);
	if (current->ret > 0 || current->nb_call <= current->nb_l)
		return (1);
	return (ft_del(&begin_list, fd, 0));
}
