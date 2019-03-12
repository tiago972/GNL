#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new_elem)
{
	if (!alst || !new_elem)
		return ;
	new_elem->next = *alst;
	*alst = new_elem;
}
