/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:00 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:40:02 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;
	t_list	*tmp;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	new_elem = f(lst);
	res = new_elem;
	tmp = lst->next;
	while (tmp)
	{
		new_elem->next = f(tmp);
		tmp = tmp->next;
		new_elem = new_elem->next;
	}
	return (res);
}
